#include <memory>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Logger.h"

namespace Engine
{
	Logger* Logger::getInstance()
	{
		static Logger* instance = nullptr;
		static std::once_flag flag;
		
		std::call_once(flag, [&]() {instance = new Logger();});

		return instance;
	}

	Logger::Logger()
	{
		console = spdlog::stdout_color_mt("console");	
		console->set_pattern("%^[%H:%M:%S] [%l] - %v%$");
	}
}
