#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Grand
{
	class GRAND_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;

	};
}


// Core log macros.
#define GRAND_CORE_TRACE(...)	::Grand::Log::getCoreLogger()->trace(__VA_ARGS__)
#define GRAND_CORE_INFO(...)	::Grand::Log::getCoreLogger()->info(__VA_ARGS__)
#define GRAND_CORE_WARN(...)	::Grand::Log::getCoreLogger()->warn(__VA_ARGS__)
#define GRAND_CORE_ERROR(...)	::Grand::Log::getCoreLogger()->error(__VA_ARGS__)
#define GRAND_CORE_FATAL(...)	::Grand::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros.
#define GRAND_TRACE(...)	::Grand::Log::getClientLogger()->trace(__VA_ARGS__)
#define GRAND_INFO(...)		::Grand::Log::getClientLogger()->info(__VA_ARGS__)
#define GRAND_WARN(...)		::Grand::Log::getClientLogger()->warn(__VA_ARGS__)
#define GRAND_ERROR(...)	::Grand::Log::getClientLogger()->error(__VA_ARGS__)
#define GRAND_FATAL(...)	::Grand::Log::getClientLogger()->fatal(__VA_ARGS__)





