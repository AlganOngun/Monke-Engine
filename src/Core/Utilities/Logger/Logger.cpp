#include "Logger.h"
#include <iostream>
#include <utility>

namespace Engine
{
	Logger& Logger::getInstance()
	{
		static Logger instance;

		return instance;
	}
}
