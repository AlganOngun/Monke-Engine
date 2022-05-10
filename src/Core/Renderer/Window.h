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


        struct deleteGLFWwindow
        {
            void operator()(GLFWwindow* ptr)
            {
                glfwDestroyWindow(ptr);
            }
        };

        using smartWindow = std::unique_ptr<GLFWwindow, deleteGLFWwindow>;
        using callbackFunctionType = std::function<void(Engine::EventSystem::Event&)>;

        struct windowProperties
        {
            std::string name;
            int width;
            int height;
            callbackFunctionType callbackFunction;
        };

		windowProperties properties;

        smartWindow window;

    public:

        Window(std::string name, int width, int height);
        Window(Window& newWindow);

        void init();
        void update();
        void setEventCallbackFunction(const callbackFunctionType& function);
    };
}
