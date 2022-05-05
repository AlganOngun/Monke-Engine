#pragma once

#include "../Macros.h"
#include "../Events/Event.h"
#include "../Events/WindowCloseEvent.h"

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
