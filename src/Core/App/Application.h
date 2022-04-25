#pragma once

#include "../Macros.h"

namespace Engine
{
	class EI Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}
