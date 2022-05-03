#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GammaEngine {

	class GAMMAENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core Log Macros
#define GAMMAENGINE_CORE_TRACE(...)  ::GammaEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GAMMAENGINE_CORE_INFO(...)   ::GammaEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GAMMAENGINE_CORE_WARN(...)   ::GammaEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GAMMAENGINE_CORE_ERROR(...)  ::GammaEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GAMMAENGINE_CORE_FATAL(...)  ::GammaEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define GAMMAENGINE_CLIENT_TRACE(...)  ::GammaEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GAMMAENGINE_CLIENT_INFO(...)   ::GammaEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define GAMMAENGINE_CLIENT_WARN(...)   ::GammaEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GAMMAENGINE_CLIENT_ERROR(...)  ::GammaEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define GAMMAENGINE_CLIENT_FATAL(...)  ::GammaEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

//If dist build
#define GAMMAENGINE_CORE_INFO