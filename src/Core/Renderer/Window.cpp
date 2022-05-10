#include "Window.h"
#include <GLFW/glfw3.h>
#include "../Events/WindowCloseEvent.h"
#include "../Events/WindowResizeEvent.h"
#include "../Utilities/Logger/Logger.h"

namespace Engine::Renderer
{
    Window::Window(std::string name, int width, int height)
    {
        GLFWwindow* windowRaw = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
        window.reset(windowRaw);

		properties.name = name;
		properties.width = width;
		properties.height = height;
    }

    Window::Window(Window& newWindow)
    {
        GLFWwindow* windowRaw = newWindow.window.release();

        window.reset(windowRaw);
    }

    void Window::init()
    {
        GLFWwindow* windowRaw = window.release();

		glfwSetWindowUserPointer(windowRaw, &properties);

        glfwSetWindowCloseCallback(windowRaw, [](GLFWwindow * win)
        {
            Engine::EventSystem::WindowCloseEvent event;

			windowProperties properties = *(windowProperties*)glfwGetWindowUserPointer(win);
			properties.callbackFunction(event);
        });

        glfwSetWindowSizeCallback(windowRaw, [](GLFWwindow * win, int width, int height)
        {
            Engine::EventSystem::WindowResizeEvent event(width, height);

			windowProperties properties = *(windowProperties*)glfwGetWindowUserPointer(win);
			properties.callbackFunction(event);
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

    void Window::setEventCallbackFunction(const callbackFunctionType& function)
    {
        properties.callbackFunction = function;
    }
}
