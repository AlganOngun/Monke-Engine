#pragma once

#include <memory>
#include <GLFW/glfw3.h>
#include <string>
#include "../Macros.h"

namespace Engine::Renderer
{
    class EI Window
    {
    private:
        std::string name;
        int width;
        int height;

        struct deleteGLFWwindow
        {
            void operator()(GLFWwindow* ptr)
            {
                glfwDestroyWindow(ptr);
            }
        };

        using smartWindow = std::unique_ptr<GLFWwindow, deleteGLFWwindow>;

        smartWindow window;

    public:
        Window(std::string name, int width, int height);
        Window(Window& newWindow);

        void update();
		bool shouldEnd();
    };
}
