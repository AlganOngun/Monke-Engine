#pragma once

#include "Event.h"

namespace Engine::EventSystem
{
    class WindowCloseEvent : public Event
    {
    public:
		inline std::string getType() {return "TypeWindowCloseEvent";};
    };
}
