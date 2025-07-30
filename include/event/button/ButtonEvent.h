// ButtonEvent.h
#ifndef BUTTONEVENT_H
#define BUTTONEVENT_H

#include "MouseEvent.h"

class ButtonEvent : public MouseEvent {
public:
    enum class Type {
        Click,
        Hover,
        Leave
    };

    ButtonEvent(int x, int y, Type t)
      : MouseEvent(x, y), _type(t)
    {}

    Type getEventType() const { return _type; }

private:
    Type _type;
};

#endif // BUTTONEVENT_H
