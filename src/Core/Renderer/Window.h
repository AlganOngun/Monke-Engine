#pragma once

#include <memory>
#include <GLFW/glfw3.h>
#include <functional>
#include "../Events/Event.h"
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
		static std::function<void(Engine::EventSystem::Event&)> callbackFunction;

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

		void init();
        void update();
		static void callCallbackFunction(const Engine::EventSystem::Event& event);
		void setEventCallbackFunction(const std::function<void(Engine::EventSystem::Event&)>& function);
    };
}
