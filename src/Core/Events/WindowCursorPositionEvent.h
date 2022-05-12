#pragma once

#include "Event.h"

namespace Engine::EventSystem
{
	class WindowCursorPositionEvent : public Event
	{
	private:
		double x{}, y{};
	public:
		WindowCursorPositionEvent();
		WindowCursorPositionEvent(double x, double y);

		std::string getType();
		void print();
	};
}
