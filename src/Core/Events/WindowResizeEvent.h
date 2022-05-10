#pragma once

#include "Event.h"

namespace Engine::EventSystem
{
    class EI WindowResizeEvent : public Event
    {
	private:
		int width{}, height{};
    public:
		WindowResizeEvent();
		WindowResizeEvent(int width, int height);
		std::string getType();

        void print();
    };
}
