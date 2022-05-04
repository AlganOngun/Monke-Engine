#include "Window.h"
#include <GLFW/glfw3.h>

namespace Engine::Renderer
{
    Window::Window(std::string name, int width, int height)
    {
        GLFWwindow* windowRaw = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
        glfwMakeContextCurrent(windowRaw);

        window.reset(windowRaw);
    }

    void Window::update()
    {
        GLFWwindow* windowRaw = window.release();

        glfwSwapBuffers(windowRaw);
        glfwPollEvents();

        window.reset(windowRaw);
    }
}
