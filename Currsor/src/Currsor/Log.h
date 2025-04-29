#pragma once

#include "PCH.h"

#include "Core.h"

namespace Currsor
{
    class CURRSOR_API Log
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


// Core log macros
#define LOG_CORE_ERROR(...)  ::Currsor::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_WARN(...)   ::Currsor::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_INFO(...)   ::Currsor::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_TRACE(...)  ::Currsor::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define LOG_ERROR(...)       ::Currsor::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_WARN(...)        ::Currsor::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_INFO(...)        ::Currsor::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_TRACE(...)       ::Currsor::Log::GetClientLogger()->trace(__VA_ARGS__)
