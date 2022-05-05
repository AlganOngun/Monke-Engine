#include "Window.h"
#include <GLFW/glfw3.h>

namespace Engine::Renderer
{
    Window::Window(std::string name, int width, int height)
    {
        GLFWwindow* windowRaw = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

        window.reset(windowRaw);
    }

	Window::Window(Window& newWindow)
	{
		GLFWwindow* windowRaw = newWindow.window.release();

		window.reset(windowRaw);
	}

    void Window::update()
    {
        GLFWwindow* windowRaw = window.release();

        glfwSwapBuffers(windowRaw);
        glfwPollEvents();

        window.reset(windowRaw);
    }

	bool Window::shouldEnd()
	{
		GLFWwindow* windowRaw = window.release();

		bool result = glfwWindowShouldClose(windowRaw);

		window.reset(windowRaw);

		return result;
	}
}
