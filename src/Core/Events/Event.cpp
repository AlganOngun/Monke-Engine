#include "Event.h"
#include "../Utilities/Logger/Logger.h"

namespace Engine::EventSystem
{
    std::string Event::getType()
    {
        return "TypeEvent";
    }

    void Event::print()
    {
		Logger::Log("Event Received: DefaultEvent");
    }
}
