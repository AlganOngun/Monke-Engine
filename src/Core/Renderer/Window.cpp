#include "Window.h"
#include <GLFW/glfw3.h>
#include "../Events/WindowCloseEvent.h"

namespace Engine::Renderer
{
	std::function<void(Engine::EventSystem::Event&)> Window::callbackFunction;

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

    void Window::init()
    {
        GLFWwindow* windowRaw = window.release();

        glfwSetWindowCloseCallback(windowRaw, [](GLFWwindow * win)
        {
            Engine::EventSystem::WindowCloseEvent event;
			Window::callbackFunction(event);
        });

		window.reset(windowRaw);
    }

    void Window::update()
    {
        GLFWwindow* windowRaw = window.release();

        glfwSwapBuffers(windowRaw);
        glfwPollEvents();

        window.reset(windowRaw);
    }

    void Window::setEventCallbackFunction(const std::function<void(Engine::EventSystem::Event&)>& function)
    {
        callbackFunction = function;
    }
}
