#ifndef COMPONENT_H
#define COMPONENT_H
#include <functional>
#include <map>
#include <string>
#include <typeindex>

#include "Event.h"

class Component {
protected:
    std::map<std::type_index, std::vector<std::function<void(Event&)>>> events;

    // 判断鼠标是否在组件内部
    // 在未来可能单独封装一个 Status 类记录组件状态
    bool hover;
public:
    virtual ~Component() = default;

    virtual void setSize(int width, int height) = 0;

    virtual void setPosition(int x, int y) = 0;

    template <typename TEvent>
    void registerEvent(const std::function<void(TEvent&)>& handler) {
        static_assert(std::is_base_of_v<Event, TEvent>, "TEvent must inherit from Event");

        this->events[typeid(TEvent)].push_back([handler](Event& e) {
            handler(static_cast<TEvent&>(e));
        });
    }

    void callEvent(Event& event) const;

    // 判断鼠标是否在组件内部
    // 在未来可能单独封装一个 Status 类记录组件状态
    void setHover(bool is_hover) { this->hover = is_hover; }
    bool isHover() { return this->hover; }
};

#endif