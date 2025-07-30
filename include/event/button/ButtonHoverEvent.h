#include"ButtonEvent.h"

// ButtonHoverEvent.h
class ButtonHoverEvent : public ButtonEvent {
public:
    ButtonHoverEvent(int x, int y)
      : ButtonEvent(x, y, Type::Hover)
    {}
};

// ButtonLeaveEvent.h
class ButtonLeaveEvent : public ButtonEvent {
public:
    ButtonLeaveEvent(int x, int y)
      : ButtonEvent(x, y, Type::Leave)
    {}
};
