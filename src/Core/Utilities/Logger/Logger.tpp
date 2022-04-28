#include "spdlog/spdlog.h"

namespace Engine
{
	Logger& Logger::getInstance()
	{
		static Logger instance;

		return instance;
	}

	template<typename... Types>
	void Logger::Log(Types... args)
	{
		getInstance().ILog((args)...);
	}

	template<typename... Types>
	void Logger::ILog(Types... args)
	{
		spdlog::info((args)...);
	}
}
