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
	void Logger::LogWarning(Types... args)
	{
		getInstance().ILogWarning((args)...);
	}

	template<typename... Types>
	void Logger::LogError(Types... args)
	{
		getInstance().ILogError((args)...);
	}

	template<typename... Types>
	void Logger::ILog(Types... args)
	{
		spdlog::info((args)...);
	}

	template<typename... Types>
	void Logger::ILogWarning(Types... args)
	{
		spdlog::warn((args)...);
	}

	template<typename... Types>
	void Logger::ILogError(Types... args)
	{
		spdlog::error((args)...);
	}
}
