#include "Application.h"
#include "../Utilities/Logger/Logger.h"
#include "../Renderer/Window.h"
#include "Context.h"

namespace Engine
{
    namespace App::Private
    {
        Engine::Context context;
        Engine::Context context2;
    }
    Application::Application()
    {
        App::Private::context.initialize();
    }

    Application::~Application()
    {
        App::Private::context.terminate();
    }

    void Application::Run()
    {
        Renderer::Window window("Test", 600, 600);
        App::Private::context.setWindow(window);

        while(!App::Private::context.shouldContextEnd()) App::Private::context.update();
    }
}
