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

	public:
		Logger(Logger const&) = delete;

		void operator=(Logger const&) = delete;

		template<typename... Types>
		static void Log(Types... var2);
	};
}

#include "Logger.tpp"
