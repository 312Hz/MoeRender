#include <iostream>

#include "mr.h"
#include "MFrame.h"
#include "event.h"
#include "MouseEvent.h"

int main() {
    MFrame frame = mr::render->Init("���Դ���", "me.wangziyang.testwindow");
    frame.setTitle("����Ԫ�������Ϸ");

    frame.registerEvent<MouseEvent>([](MouseEvent& e) {
        std::cout << "Mouse: " << e.getX() << ", " << e.getY() << std::endl;
    });

    MouseEvent event(20, 30);
    frame.callEvent(event);
    // frame.callEvent(MouseEvent(20, 30));

    while (true) {}
}
