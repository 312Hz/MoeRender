#include <iostream>
#include <MouseLeaveEvent.h>

#include "mr.h"
#include "MFrame.h"
#include "event.h"
#include "MouseEvent.h"
#include "MouseHoverEvent.h"

int main() {
    MFrame frame = mr::render->Init("测试代码", "me.wangziyang.testwindow");
    frame.setTitle("二次元不会打游戏");

    frame.registerEvent<MouseEvent>([](MouseEvent& e) {
        std::cout << "Mouse: " << e.getX() << ", " << e.getY() << std::endl;
    });

    frame.registerEvent<MouseHoverEvent>([](MouseHoverEvent& e) {
        std::cout << "MouseHoverEvent: " << e.getX() << ", " << e.getY() << std::endl;
    });

    frame.registerEvent<MouseLeaveEvent>([](MouseLeaveEvent& e) {
        std::cout << "MouseLeaveEvent: " << e.getX() << ", " << e.getY() << std::endl;
    });

    MouseEvent event(20, 30);
    frame.callEvent(event);

    while (true) {}
}
