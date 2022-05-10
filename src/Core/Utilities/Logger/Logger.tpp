namespace Engine
{
	template<typename... Types>
	void Logger::Log(std::string message, Types... args)
	{
		getInstance()->ILog(message, (args)...);
	}

	template<typename... Types>
	void Logger::LogWarning(std::string message, Types... args)
	{
		getInstance()->ILogWarning(message, (args)...);
	}

	template<typename... Types>
	void Logger::LogError(std::string message, Types... args)
	{
		getInstance()->ILogError(message, (args)...);
	}

	template<typename... Types>
	void Logger::ILog(std::string message, Types... args)
	{
		console->info(message, (args)...);
	}

	template<typename... Types>
	void Logger::ILogWarning(std::string message, Types... args)
	{
		console->warn(message, (args)...);
	}

	template<typename... Types>
	void Logger::ILogError(std::string message, Types... args)
	{
		console->error(message, (args)...);
	}
}
