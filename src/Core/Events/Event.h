#pragma once

#include "../Macros.h"
#include <string>

namespace Engine::EventSystem
{
    class EI Event
    {
	public:
		inline virtual std::string getType() {return "TypeEvent";};
    };
}
