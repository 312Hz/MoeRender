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
     * ͨ�� HWND ��ȡ����<br>
     * �˷�ʽ������ Windows ƽ̨
     *
     * @param hwnd HWND
     * @return MFrame ����
     */
    extern MFrame getFrameByHWND(HWND hwnd);
}

#endif