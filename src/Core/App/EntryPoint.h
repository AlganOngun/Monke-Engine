#pragma once

#include <iostream>

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Engine::CreateApplication();
	std::cout << "Hi" << std::endl;
	app->Run();
	delete app;
}
