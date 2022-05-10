#include "KeyPressedEvent.h"
#include "../Utilities/Logger/Logger.h"

namespace Engine::EventSystem
{
	KeyPressedEvent::KeyPressedEvent() {}
	
	KeyPressedEvent::KeyPressedEvent(int key)
	{
		this->key = key;
	}

	std::string KeyPressedEvent::getType()
	{
		return "TypeKeyPressedEvent";
	}

	void KeyPressedEvent::print()
	{
		Logger::Log("Event Received: KeyPressedEvent; key: {}", key);
	}
}
