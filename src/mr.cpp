#include "mr.h"

#ifdef _WIN32
    #include "WindowsRender.h"
#elif __linux__
    #include "LinuxRender.h"
#elif __APPLE__
    #include "MacRender.h"
#endif

namespace mr
{
    std::unique_ptr<Render> createRender()
    {
        #ifdef _WIN32
        return std::make_unique<WindowsRender>();
        #elif __linux__
        return std::make_unique<LinuxRender>();
        #elif __APPLE__
        return std::make_unique<MacRender>();
        #else
        #error "Unsupported platform"
        #endif
    }

    // ����ȫ��ʵ��
    std::unique_ptr<Render> render = createRender();
    std::vector<MFrame> frames;

    /**
     * ͨ�� HWND ��ȡ����<br>
     * �˷�ʽ������ Windows ƽ̨
     *
     * @param hwnd HWND
     * @return MFrame ����
     */
    MFrame getFrameByHWND(HWND hwnd)
    {
        for (auto frame : frames)
        {
            if (hwnd != frame.hwnd)
                continue;

            return frame;
        }

        return MFrame(nullptr);
    }
}