#include "MFrame.h"

#include <iostream>

#include "TextField.h"
#include "WindowsRender.h"

MFrame::MFrame(HWND hWnd): _closed(false)
{
    render = std::make_unique<WindowsRender>();
    hwnd = hWnd;
}

// 其他方法实现
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

    if (typeid(*component) == typeid(TextField))
    {
        TextField* textField = dynamic_cast<TextField*>(component);

        CreateWindowExA(
            0, "STATIC", textField->getText().c_str(),
            WS_CHILD | WS_VISIBLE,
            textField->getX(), textField->getY(), textField->getWidth(), textField->getHeight(),
            this->hwnd,
            reinterpret_cast<HMENU>(this->components.size()),
            GetModuleHandle(nullptr),
            nullptr
        );

        UpdateWindow(this->hwnd);
    }
}
