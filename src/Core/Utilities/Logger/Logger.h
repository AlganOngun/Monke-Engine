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
		void ILog(std::string message, Types... var2);

	public:
		Logger(Logger const&) = delete;

		void operator=(Logger const&) = delete;

		template<typename... Types>
		static void Log(std::string message, Types... var2);
	};
}
