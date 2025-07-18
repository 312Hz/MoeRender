#include "Component.h"

#include <typeindex>

void Component::callEvent(Event& event) const
{
    auto eventType = std::type_index(typeid(event));

    auto it = events.find(eventType);

    if (it == events.end())
        return;

    for (const auto& handler : it->second)
        handler(event);
}