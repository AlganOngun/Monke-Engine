#pragma once

#include "Event.h"
#include "../Macros.h"

#include <string>
#include <functional>

class EI PrintEvent : public Event
{
	std::function<void(PrintEvent)> listenerFunction;
	std::string message;
public:
	PrintEvent(std::string message, std::function<void(PrintEvent)> listenerFunction) : message(message), listenerFunction(listenerFunction) {}

	void dispatch();
	std::string getMessage();
};
