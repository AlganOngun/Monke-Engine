#include "Context.h"
#include "GLFW/glfw3.h"

namespace Engine
{
	void Context::initialize()
	{
		glfwInit();	
	}

	void Context::terminate()
	{
		glfwTerminate();
	}

	void Context::setWindow(Renderer::Window window)
	{
		Renderer::Window* dynamicWindow = new Renderer::Window(window);
		this->window.reset(dynamicWindow);
	}

	void Context::update()
	{
		window->update();
	}
}
