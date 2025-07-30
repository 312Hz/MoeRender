// ButtonClickEvent.h
#ifndef BUTTONCLICKEVENT_H
#define BUTTONCLICKEVENT_H

#include "ButtonEvent.h"

class ButtonClickEvent : public ButtonEvent {
public:
    // 传给基类的 Type 一定写成 Click
    ButtonClickEvent(int x, int y)
      : ButtonEvent(x, y, Type::Click)
    {}
};

#endif // BUTTONCLICKEVENT_H
