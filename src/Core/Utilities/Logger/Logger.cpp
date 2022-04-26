#include "Logger.h"
#include <iostream>
#include <spdlog/spdlog.h>
#include <utility>

namespace Engine
{
	Logger& Logger::getInstance()
	{
		static Logger instance;

		return instance;
	}

	template<typename... Types>
	void Logger::Log(std::string message, Types... var2)
	{
		getInstance().ILog(message, std::forward<Types>(var2)...);
	}

	template<typename... Types>
	void Logger::ILog(std::string message, Types... var2)
	{
		spdlog::info(message, std::forward<Types>(var2)...);
	}
}
