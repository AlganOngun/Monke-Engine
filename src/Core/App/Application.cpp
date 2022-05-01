#include "Application.h"
#include "../Utilities/Logger/Logger.h"
#include "../Events/PrintEvent.h"
#include <functional>

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
		
		PrintEvent event("Hello Print Event", listener);
		event.dispatch();
	}
}
