#include "Application.h"
#include "../Renderer/Window.h"
#include "../EventSystem/EventDispatcher.h"
#include "../Utilities/Logger/Logger.h"
#include "Context.h"

namespace Engine
{
    namespace App::Private
    {
        Engine::Context context;
    }
    Application::Application()
    {
        App::Private::context.initialize();
    }

    Application::~Application()
    {
        App::Private::context.terminate();
    }

    void Application::OnEvent(Engine::EventSystem::Event& e)
    {
		e.print();
        EventSystem::EventDispatcher dispatcher(e);
        dispatcher.dispatch<EventSystem::WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
    }

    void Application::OnWindowClose(EventSystem::WindowCloseEvent& e)
    {
        isRunning = false;
    }

    void Application::Run()
    {
        Renderer::Window window("Test", 600, 600);
        window.setEventCallbackFunction(std::bind(&Application::OnEvent, this, std::placeholders::_1));
        window.init();

        App::Private::context.setWindow(window);

        while(isRunning)
        {
            App::Private::context.update();
        }
    }

}
