#pragma once

#include <memory>
#include <GLFW/glfw3.h>
#include <string>

namespace Engine::Renderer
{
    class Window
    {
    private:
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

		void update();
    };
}
