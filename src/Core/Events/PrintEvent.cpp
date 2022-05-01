#include "PrintEvent.h"

void PrintEvent::dispatch()
{
	listenerFunction(*this);
}

std::string PrintEvent::getMessage()
{
	return message;
}
