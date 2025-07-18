#include "WindowsRender.h"

#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

#include "mr.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

MFrame WindowsRender::Init(LPCSTR title, LPCSTR className) const
{
    if (HWND console = GetConsoleWindow(); console != nullptr)
        ShowWindow(console, SW_HIDE);

    HWND hwnd = nullptr;
    bool ready = false;
    std::mutex mtx;
    std::condition_variable cv;

    auto promise = std::make_shared<std::promise<MFrame>>();
    auto frameFuture = promise->get_future();

    std::thread t([title, className, &hwnd, &ready, &mtx, &cv](std::shared_ptr<std::promise<MFrame>> promisePtr)
    {
        HINSTANCE hInstance = GetModuleHandle(nullptr);

        WNDCLASSEX wc{sizeof(WNDCLASSEX)};
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = WndProc;
        wc.hInstance = hInstance;
        wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
        wc.lpszClassName = className;

        if (!RegisterClassEx(&wc))
        {
            MessageBox(nullptr, "注册窗口类失败！", "错误", MB_ICONERROR);
            return;
        }

        hwnd = CreateWindowEx(0, className,
            title,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            800, 600,
            nullptr, nullptr,
            hInstance,
            nullptr
        );

        MFrame frame = MFrame(hwnd);
        promisePtr->set_value(MFrame(hwnd));

        if (!hwnd)
        {
            MessageBox(nullptr, "创建窗口失败！", "错误", MB_ICONERROR);
            return;
        }


        // 1) 静态文本
        CreateWindowExA(
            0, "STATIC", "请输入名字：",
            WS_CHILD | WS_VISIBLE,
            20, 20, 100, 20,
            hwnd,
            reinterpret_cast<HMENU>(1001),
            hInstance,
            nullptr
        );

        // 2) 单行编辑框
        CreateWindowExA(
            WS_EX_CLIENTEDGE, "EDIT", nullptr,
            WS_CHILD | WS_VISIBLE | ES_LEFT,
            130, 18, 200, 24,
            hwnd,
            reinterpret_cast<HMENU>(1002),
            hInstance,
            nullptr
        );

        // 3) 提交按钮
        CreateWindowExA(
            0, "BUTTON", "提交",
            WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
            350, 18, 80, 24,
            hwnd,
            reinterpret_cast<HMENU>(1003),
            hInstance,
            nullptr
        );

        // 4) 垂直滚动条控件
        HWND hScroll = CreateWindowExA(
            0, "SCROLLBAR", nullptr,
            WS_CHILD | WS_VISIBLE | SBS_VERT,
            760, 20, 20, 200, // 放在窗口右侧
            hwnd,
            reinterpret_cast<HMENU>(1004),
            hInstance,
            nullptr
        );
        // 设置滚动条范围和初始位置
        SCROLLINFO si = {sizeof(si)};
        si.fMask = SIF_RANGE | SIF_POS;
        si.nMin = 0;
        si.nMax = 100;
        si.nPos = 0;
        SetScrollInfo(hScroll, SB_CTL, &si, TRUE);

        // —— 控件添加完毕 —— //

        // 显示并刷新窗口
        ShowWindow(hwnd, SW_SHOWDEFAULT);
        UpdateWindow(hwnd);

        ShowWindow(hwnd, SW_SHOWDEFAULT);
        UpdateWindow(hwnd);

        {
            std::lock_guard lock(mtx);
            ready = true;
        }

        cv.notify_one();

        MSG msg;
        while (GetMessage(&msg, nullptr, 0, 0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }, promise);

    t.detach();

    std::unique_lock lock(mtx);
    cv.wait(lock, [&ready] { return ready; });

    const MFrame frame = frameFuture.get();
    mr::frames.push_back(frame);
    return frame;
}

LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_NCDESTROY:
        mr::getFrameByHWND(hwnd).setClosed(true);
        std::cout << "窗口完全销毁" << std::endl;
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

void WindowsRender::SetTitle(const Component* component, std::string title) const
{
    if (typeid(*component) == typeid(MFrame))
    {
        const auto* frame = dynamic_cast<const MFrame*>(component);

        if (!IsWindow(frame->hwnd))
        {
            std::cerr << "错误：无效窗口句柄" << std::endl;
            return;
        }

        PostMessage(frame->hwnd, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(title.c_str()));
        SetWindowTextA(frame->hwnd, title.c_str());
    }
}

void WindowsRender::SetSize(const Component* component, const int width, const int height) const
{
    if (typeid(*component) == typeid(MFrame))
    {
        const auto* frame = dynamic_cast<const MFrame*>(component);
        SetWindowPos(frame->hwnd, nullptr, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER);
    }
}