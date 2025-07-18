#ifndef WINDOWSRENDER_H
#define WINDOWSRENDER_H

#include "Render.h"

class WindowsRender: public Render {
    MFrame Init(LPCSTR title, LPCSTR className) const override;

    void SetTitle(const Component* component, std::string title) const override;
    void SetSize(const Component* component, int width, int height) const override;
};

#endif