#ifndef MFRAME_H
#define MFRAME_H

#include <memory>
#include <windows.h>

#include "Component.h"

class Render;

class MFrame: public Component {
protected:
    std::shared_ptr<Render> render;
    bool _closed;
public:
#ifdef _WIN32
    HWND hwnd;
    explicit MFrame(HWND hWnd);
#elif __linux__
    // Linux ДњТы
#endif

    void setSize(int width, int height) const;
    void setTitle(std::string title) const;

    void setClosed(bool closed);
    bool closed() const;
};

#endif // MFRAME_H
