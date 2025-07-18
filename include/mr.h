#ifndef MR_H
#define MR_H

#include <memory>
#include <vector>

#include "Render.h"

namespace mr
{
    extern std::unique_ptr<Render> render;
    extern std::vector<MFrame> frames;

    /**
     * 通过 HWND 获取窗口<br>
     * 此方式适用于 Windows 平台
     *
     * @param hwnd HWND
     * @return MFrame 对象
     */
    extern MFrame getFrameByHWND(HWND hwnd);
}

#endif