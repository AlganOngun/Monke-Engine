#include "../Events/Event.h"
#include "EventDispatcher.h"
#include <algorithm>

EventDispatcher& EventDispatcher::getInstance()
{
    static EventDispatcher instance;

    return instance;
}

void EventDispatcher::IdispatchEvents()
{
    while(!eventQueue.empty())
    {
        eventQueue.front()->dispatch();
        eventQueue.pop();
    }
}

void EventDispatcher::Ipush(std::unique_ptr<Event>& event)
{
    eventQueue.push(std::move(event));
}

void EventDispatcher::push(std::unique_ptr<Event>& event)
{
    getInstance().Ipush(event);
}

void EventDispatcher::dispatchEvents()
{
    getInstance().IdispatchEvents();
}
