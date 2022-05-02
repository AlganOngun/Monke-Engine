#pragma once

#include <queue>
#include <memory>
#include "../Macros.h"
#include "../Events/Event.h"

class EI EventDispatcher
{
public:
    static EventDispatcher& getInstance();

private:
    std::queue<std::unique_ptr<Event>> eventQueue;

	EventDispatcher() {}

	void Ipush(std::unique_ptr<Event>& event);
	void IdispatchEvents();

public:
	EventDispatcher(EventDispatcher const&) = delete;

	void operator=(EventDispatcher const&) = delete;

    static void push(std::unique_ptr<Event>& event);
    static void dispatchEvents();
};
