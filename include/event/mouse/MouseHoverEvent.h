#ifndef MOUSEHOVEREVENT_H
#define MOUSEHOVEREVENT_H

#include "MouseEvent.h"

class MouseHoverEvent final : public MouseEvent
{
public:
    MouseHoverEvent(int x, int y): MouseEvent(x, y) {}
};

#endif