#include "WindowResizeEvent.h"
#include "../Utilities/Logger/Logger.h"

namespace Engine::EventSystem
{
	WindowResizeEvent::WindowResizeEvent() {}

	WindowResizeEvent::WindowResizeEvent(int width, int height)
	{
		this->width = width;
		this->height = height;
	}

	std::string WindowResizeEvent::getType()
	{
		return "TypeWindowResizeEvent";
	}

	void WindowResizeEvent::print()
	{
		Logger::Log("Event Received: WindowResizeEvent; width: {}, height: {}", width, height);
	}
}
