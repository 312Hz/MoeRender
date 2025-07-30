#ifndef RENDER_H
#define RENDER_H

#include <windows.h>

#include "MFrame.h"

class Render {
public:
    // virtual void render() const = 0; //新增的渲染方式的接口
    virtual ~Render() = default;
    virtual MFrame Init(LPCSTR title, LPCSTR className) = 0;
    virtual void SetTitle(const Component* component, std::string title) const = 0;
    virtual void SetSize(const Component* component, int width, int height) const = 0;
};

#endif