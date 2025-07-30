// ButtonClickEvent.h
#ifndef BUTTONCLICKEVENT_H
#define BUTTONCLICKEVENT_H

#include "ButtonEvent.h"

class ButtonClickEvent : public ButtonEvent {
public:
    // ��������� Type һ��д�� Click
    ButtonClickEvent(int x, int y)
      : ButtonEvent(x, y, Type::Click)
    {}
};

#endif // BUTTONCLICKEVENT_H
