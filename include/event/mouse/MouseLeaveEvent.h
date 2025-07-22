#ifndef MOUSELEAVEEVENT_H
#define MOUSELEAVEEVENT_H

#include "MouseEvent.h"

class MouseLeaveEvent final : public MouseEvent
{
public:
    MouseLeaveEvent(int x, int y)
        : MouseEvent(x, y)
    {}
};

#endif // MOUSELEAVEEVENT_H