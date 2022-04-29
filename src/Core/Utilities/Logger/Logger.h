#pragma once

#include "../../Macros.h"
#include <string>

namespace Engine
{
	class EI Logger
	{
	public:
		static Logger& getInstance();

	private:
		Logger() {}

		template<typename... Types>
		void ILog(Types... args);

		template<typename... Types>
		void ILogWarning(Types... args);

		template<typename... Types>
		void ILogError(Types... args);

	public:
		Logger(Logger const&) = delete;

		void operator=(Logger const&) = delete;

		template<typename... Types>
		static void Log(Types... args);

		template<typename... Types>
		static void LogWarning(Types... args);

		template<typename... Types>
		static void LogError(Types... args);
	};
}

#include "Logger.tpp"
