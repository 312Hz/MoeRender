#include "Component.h"

#include <iostream>
#include <typeindex>

void Component::callEvent(Event& event) const
{
    auto eventType = std::type_index(typeid(event));

    auto it = this->events.find(eventType);

    if (it == this->events.end())
        return;

    for (const auto& handler : it->second)
        handler(event);
}
