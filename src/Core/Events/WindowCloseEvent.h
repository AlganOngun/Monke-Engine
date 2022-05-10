#pragma once

#include "Event.h"

namespace Engine::EventSystem
{
    class EI WindowCloseEvent : public Event
    {
    public:
        std::string getType();

        void print();
    };
}
