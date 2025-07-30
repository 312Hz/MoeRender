#include <iostream>
#include <MouseLeaveEvent.h>

#include "mr.h"
#include "MFrame.h"
#include "event.h"
#include "MouseEvent.h"
#include "MouseHoverEvent.h"
#include "TextField.h"
#include "Button.h"


int main() {
    MFrame frame = mr::render->Init("���Դ���", "me.wangziyang.testwindow");
    frame.setTitle("����Ԫ�������Ϸ");

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

    //��ť�¼�

    TextField textField("Test", 100, 20);
    textField.setPosition(20, 20);
    frame.addComponent(&textField);

    //Ŀǰ��������������δ���Ե��
    Button btn("TButton", 100, 20);
    btn.setPosition(100, 50);
    frame.addComponent(&btn);


    //������Ҫ�Ż�һ�� �������Ǳ�׼��win32ѭ��,֮ǰ����ԭ������Ϊ ���жѻ�����Ϣ�ò����� ����ֱ�ӻ����
    MSG msg;
    while (true) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) break;
            TranslateMessage(&msg);
            DispatchMessage(&msg); //����
        }
        // ������Է���Ķ�ʱ���¡���������Ⱦ֮��ĵ���
    }
}
