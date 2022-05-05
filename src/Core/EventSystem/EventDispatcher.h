#pragma once

#include <functional>
#include <memory>
#include "../Macros.h"
#include "../Events/Event.h"

namespace Engine::EventSystem
{
    class EI EventDispatcher
    {
	private:
		Event& event;
	public:
		EventDispatcher(Event& event) : event(event) {}

		template<typename T>
		void dispatch(const std::function<void(T&)>& callback)
		{
			T dummy;
			if(event.getType() == dummy.getType())
			{
				callback(*(T*)&event);
			}
		}
    };
}
