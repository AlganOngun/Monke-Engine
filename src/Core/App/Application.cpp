#include "Application.h"
#include "../Utilities/Logger/Logger.h"
#include "../Renderer/Window.h"
#include "GLFW/glfw3.h"

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
		glfwInit();

		Renderer::Window window("Test", 600, 600);

		while(true)
		{
			window.update();
		}

		glfwTerminate();
    }
}
