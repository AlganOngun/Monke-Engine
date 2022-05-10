#pragma once

#include "Event.h"

namespace Engine::EventSystem
{
	//TODO: Refactor this class to use Key class instead of int

	class EI KeyPressedEvent : public Event
	{
	private:
		int key{};
	public:
		KeyPressedEvent();
		KeyPressedEvent(int key);

		std::string getType();
		void print();
	};
}
