#pragma once

#include "Event.h"

namespace Engine::EventSystem
{
	//TODO: Refactor this class to use Key class instead of int

	class EI KeyReleasedEvent : public Event
	{
	private:
		int key{};
	public:
		KeyReleasedEvent();
		KeyReleasedEvent(int key);

		std::string getType();
		void print();
	};
}
