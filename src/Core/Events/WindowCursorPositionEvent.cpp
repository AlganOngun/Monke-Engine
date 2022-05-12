#include "WindowCursorPositionEvent.h"
#include "../Utilities/Logger/Logger.h"

namespace Engine::EventSystem
{
	WindowCursorPositionEvent::WindowCursorPositionEvent() {}
	
	WindowCursorPositionEvent::WindowCursorPositionEvent(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	std::string WindowCursorPositionEvent::getType()
	{
		return "TypeWindowCursorPositionEvent";
	}

	void WindowCursorPositionEvent::print()
	{
		Logger::Log("Event Received: WindowCursorPositionEvent; x: {}, y: {}", x, y);
	}
}
