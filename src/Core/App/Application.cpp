#include "Application.h"
#include "../Utilities/Logger/Logger.h"
#include "../Events/PrintEvent.h"
#include "../EventSystem/EventDispatcher.h"
#include <functional>
#include <memory>

namespace Engine
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		std::function<void(PrintEvent)> listener = [](PrintEvent e) {Logger::Log(e.getMessage());};
		
		auto event = std::unique_ptr<Event>{std::make_unique<PrintEvent>(PrintEvent("Hello Print Event", listener))};
		auto event2 = std::unique_ptr<Event>{std::make_unique<PrintEvent>(PrintEvent("Hi Print Event", listener))};
		auto event3 = std::unique_ptr<Event>{std::make_unique<PrintEvent>(PrintEvent("This is the 3rd print event", listener))};

		EventDispatcher::push(event);
		EventDispatcher::push(event2);
		EventDispatcher::push(event3);
		
		EventDispatcher::dispatchEvents();
	}
}
