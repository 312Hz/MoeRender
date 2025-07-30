#include "MFrame.h"

#include <iostream>

#include "Button.h"
#include "TextField.h"
#include "WindowsRender.h"

MFrame::MFrame(HWND hWnd): _closed(false)
{
    render = std::make_unique<WindowsRender>();
    hwnd = hWnd;
}

// ��������ʵ��
void MFrame::setSize(int width, int height)
{
    render->SetSize(this, width, height);
}

void MFrame::setTitle(const std::string title) const
{
    render->SetTitle(this, title);
}

void MFrame::setClosed(bool closed)
{
    _closed = closed;
}

bool MFrame::closed() const
{
    return _closed;
}

void MFrame::setPosition(int x, int y)
{

}

void MFrame::addComponent(Component* component)
{
    this->components.push_back(component);

    if (typeid(*component) == typeid(TextField)) {
        TextField* textField = dynamic_cast<TextField*>(component);

        constexpr int IDC_TEXTFIELD_BASE = 1000;
        int ctrlId = IDC_TEXTFIELD_BASE + static_cast<int>(this->components.size());
        CreateWindowExA(
            0, "STATIC", textField->getText().c_str(),
            WS_CHILD | WS_VISIBLE,
            textField->getX(), textField->getY(), textField->getWidth(), textField->getHeight(),
            this->hwnd,
            reinterpret_cast<HMENU>(this->components.size()),
            GetModuleHandle(nullptr),
            nullptr
        );
    }
    else if (typeid(*component) == typeid(Button))
    {
        auto* btn = static_cast<Button*>(component);

        constexpr int IDC_BUTTON_BASE = 2000;
        int ctrlId = IDC_BUTTON_BASE + static_cast<int>(this->components.size());
        //���ڲ���Ҫ����ֵ
           HWND hBtn = CreateWindowExA(
            0,
            "BUTTON",                     // ԭ����ť��
            btn->getText().c_str(),       // ��ť�ϵ�����
            WS_CHILD | WS_VISIBLE         // �ӿؼ� + �ɼ�
            | BS_PUSHBUTTON               // ��ͨ��ť��ʽ
            | WS_TABSTOP,                 // ��ͨ�� Tab ���л�
            btn->getX(),                  // x
            btn->getY(),                  // y
            btn->getWidth(),              // width
            btn->getHeight(),             // height
            this->hwnd,                   // ������
            reinterpret_cast<HMENU>(ctrlId),
            GetModuleHandle(nullptr),
            nullptr
        );
        btn->setNativeHandle(hBtn);
        btn->setCtrlId(ctrlId);
        UpdateWindow(this->hwnd);
    }
}
