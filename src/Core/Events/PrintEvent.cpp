#include "PrintEvent.h"

namespace Engine::EventSystem
{
    void PrintEvent::dispatch()
    {
        listenerFunction(*this);
    }

    std::string PrintEvent::getMessage()
    {
        return message;
    }
}
