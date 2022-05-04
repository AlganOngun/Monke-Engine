#pragma once

#include "../Macros.h"
#include <functional>

namespace Engine::EventSystem
{
    class EI Event
    {
        public:
            virtual void dispatch() = 0;
    };
}
