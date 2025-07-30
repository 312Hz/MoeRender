#ifndef MFRAME_H
#define MFRAME_H

#include <memory>

#ifdef _WIN32
#include <windows.h>
#elif __linux__
// do something
#endif

#include "Component.h"

class Render;

class MFrame: public Component {
protected:
    std::shared_ptr<Render> render;
    bool _closed;
    std::vector<Component*> components;
public:
#ifdef _WIN32
    HWND hwnd;
    explicit MFrame(HWND hWnd);
#elif __linux__
    // Linux ДњТы
#endif

    void setSize(int width, int height);
    void setTitle(std::string title) const;

    void setPosition(int x, int y);

    void setClosed(bool closed);
    bool closed() const;

    void addComponent(Component* component);
    const std::vector<Component*>& getComponents() const {
        return components;
    }
};

#endif
