#pragma once

#include "../Macros.h"

namespace Engine::EventSystem
{
	class Event;
	class WindowCloseEvent;
}

namespace Engine
{
	class EI Application
	{
	private:
		bool isRunning = true;
	public:
		Application();

		virtual ~Application();

		void Run();
		void OnEvent(Engine::EventSystem::Event& e);
		void OnWindowClose(Engine::EventSystem::WindowCloseEvent& e);
	};

	Application* CreateApplication();
}
