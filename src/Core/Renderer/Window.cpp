#include "Window.h"
#include <GLFW/glfw3.h>
#include "../Events/WindowCloseEvent.h"
#include "../Events/WindowResizeEvent.h"
#include "../Events/KeyReleasedEvent.h"
#include "../Events/KeyPressedEvent.h"
#include "../Events/WindowCursorPositionEvent.h"
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

        glfwSetWindowCloseCallback(windowRaw, [](GLFWwindow * window)
        {
            Engine::EventSystem::WindowCloseEvent event;

            windowProperties properties = *(windowProperties*)glfwGetWindowUserPointer(window);
            properties.callbackFunction(event);
        });

        glfwSetWindowSizeCallback(windowRaw, [](GLFWwindow * window, int width, int height)
        {
            Engine::EventSystem::WindowResizeEvent event(width, height);

            windowProperties properties = *(windowProperties*)glfwGetWindowUserPointer(window);
            properties.callbackFunction(event);
        });

        glfwSetKeyCallback(windowRaw, [](GLFWwindow * window, int key, int scancode, int action, int mods)
        {
            windowProperties properties = *(windowProperties*)glfwGetWindowUserPointer(window);

            switch(action)
            {
                case GLFW_PRESS:
                {
                    EventSystem::KeyPressedEvent event(key);
                    properties.callbackFunction(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    EventSystem::KeyReleasedEvent event(key);
                    properties.callbackFunction(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    EventSystem::KeyPressedEvent event(key);
                    properties.callbackFunction(event);
                    break;
                }
            }
        });

        glfwSetCursorPosCallback(windowRaw, [](GLFWwindow * window, double x, double y)
        {
            windowProperties properties = *(windowProperties*)glfwGetWindowUserPointer(window);

			Engine::EventSystem::WindowCursorPositionEvent event(x, y);
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
