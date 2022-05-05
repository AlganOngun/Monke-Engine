#pragma once

#include "../Renderer/Window.h"
#include "../Macros.h"

namespace Engine
{
    class EI Context
    {
    private:
		std::unique_ptr<Renderer::Window> window;
	
	public:
		void initialize();
		void terminate();

		void setWindow(Renderer::Window window);
		void update();
    };
}
