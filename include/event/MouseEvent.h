#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H
#include "Event.h"

class MouseEvent: public Event {
private:
    int x;
    int y;
public:
    MouseEvent(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int getX()
    {
        return this->x;
    }

    int getY()
    {
        return this->y;
    }
};

#endif