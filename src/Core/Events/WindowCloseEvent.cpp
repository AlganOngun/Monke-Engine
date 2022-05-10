#include "WindowCloseEvent.h"
#include "../Utilities/Logger/Logger.h"

namespace Engine::EventSystem
{
	std::string WindowCloseEvent::getType()
	{
		return "TypeWindowCloseEvent";
	}

	void WindowCloseEvent::print()
	{
		Logger::Log("Event Received: WindowCloseEvent");
	}
}
