#pragma once

#include <spdlog/spdlog.h>

#include <string>
#include <memory>
#include <vector>
#include <sstream>

namespace C8VM
{
	class Logger
	{
	public:
		static void Init(const std::string& name = "C8VMLogger");
		static void Destroy();
		inline static std::shared_ptr<spdlog::logger> GetLogger() { return s_Logger; }

		static void SaveLastLog();
		static void Clear();
		static const std::vector<std::string>& GetLogs();

	private:
		inline static std::shared_ptr<spdlog::logger> s_Logger;
		inline static std::vector<std::string> s_Logs;
		inline static std::ostringstream s_Stream;
	};
}

#define C8VM_LOG_INFO(...)		(C8VM::Logger::GetLogger()->info(__VA_ARGS__), C8VM::Logger::SaveLastLog())
#define C8VM_LOG_WARN(...)		(C8VM::Logger::GetLogger()->warn(__VA_ARGS__), C8VM::Logger::SaveLastLog())
#ifdef C8VM_DEBUG
	#define C8VM_LOG_DEBUG(...)		(C8VM::Logger::GetLogger()->debug(__VA_ARGS__), C8VM::Logger::SaveLastLog())
#else
	#define C8VM_LOG_DEBUG(...)
#endif
#define C8VM_LOG_ERROR(...)		(C8VM::Logger::GetLogger()->error(__VA_ARGS__), C8VM::Logger::SaveLastLog())
#define C8VM_LOG_CRITICAL(...)	(C8VM::Logger::GetLogger()->critical(__VA_ARGS__), C8VM::Logger::SaveLastLog(), throw)
#define C8VM_LOG_TRACE(...)		(C8VM::Logger::GetLogger()->trace(__VA_ARGS__), C8VM::Logger::SaveLastLog(), __VA_ARGS__))
