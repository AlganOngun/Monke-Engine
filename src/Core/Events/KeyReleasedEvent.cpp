#include "KeyReleasedEvent.h"
#include "../Utilities/Logger/Logger.h"

namespace Engine::EventSystem
{
	KeyReleasedEvent::KeyReleasedEvent() {}
	
	KeyReleasedEvent::KeyReleasedEvent(int key)
	{
		this->key = key;
	}

	std::string KeyReleasedEvent::getType()
	{
		return "TypeKeyReleasedEvent";
	}

	void KeyReleasedEvent::print()
	{
		Logger::Log("Event Received: KeyReleasedEvent; key: {}", key);
	}
}
