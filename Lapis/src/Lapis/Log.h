#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Lapis
{
	class LAPIS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log Macros
#define LP_CORE_TRACE(...) ::Lapis::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LP_CORE_INFO(...)  ::Lapis::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LP_CORE_WARN(...)  ::Lapis::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LP_CORE_ERROR(...) ::Lapis::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LP_CORE_FATAL(...) ::Lapis::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log Macros
#define LP_TRACE(...) ::Lapis::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LP_INFO(...)  ::Lapis::Log::GetClientLogger()->info(__VA_ARGS__)
#define LP_WARN(...)  ::Lapis::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LP_ERROR(...) ::Lapis::Log::GetClientLogger()->error(__VA_ARGS__)
#define LP_FATAL(...) ::Lapis::Log::GetClientLogger()->fatal(__VA_ARGS__)