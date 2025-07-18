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
public:
    virtual ~Component() = default;

    virtual void setTitle(std::string title) const = 0;
    virtual void setSize(int width, int height) const = 0;

    template <typename TEvent>
    void registerEvent(const std::function<void(TEvent&)>& handler) {
        static_assert(std::is_base_of_v<Event, TEvent>, "TEvent must inherit from Event");

        this->events[typeid(TEvent)].push_back([handler](Event& e) {
            handler(static_cast<TEvent&>(e));
        });
    }

    void callEvent(Event& event) const;
};

#endif