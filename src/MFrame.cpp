#include "MFrame.h"

#include "WindowsRender.h"

MFrame::MFrame(HWND hWnd): _closed(false)
{
    render = std::make_unique<WindowsRender>();
    hwnd = hWnd;
}

// 其他方法实现
void MFrame::setSize(int width, int height) const
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
