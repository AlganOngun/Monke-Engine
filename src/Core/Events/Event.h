#pragma once

#include "../Macros.h"
#include <string>

namespace Engine::EventSystem
{
    class EI Event
    {
    public:
        virtual std::string getType();

        virtual void print();
    };
}
