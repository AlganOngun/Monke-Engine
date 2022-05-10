#pragma once

#include "../../Macros.h"
#include <memory>
#include <string>
#include <spdlog/spdlog.h>

namespace Engine
{
	class EI Logger
	{
	public:
		static Logger* getInstance();

	private:

		template<typename... Types>
		void ILog(std::string message, Types... args);

		template<typename... Types>
		void ILogWarning(std::string message, Types... args);

		template<typename... Types>
		void ILogError(std::string message, Types... args);

		std::shared_ptr<spdlog::logger> console;

	public:

		Logger();

		template<typename... Types>
		static void Log(std::string message, Types... args);

		template<typename... Types>
		static void LogWarning(std::string message, Types... args);

		template<typename... Types>
		static void LogError(std::string message, Types... args);
	};
}

#include "Logger.tpp"
