#pragma once

#ifdef CS_PLATFORM_WINDOWS
    #ifdef CS_BUILD_DLL
        #define CURRSOR_API __declspec(dllexport)
    #else
        #define CURRSOR_API __declspec(dllimport)
    #endif
#else
    #error Currsor only supports Windows!
#endif

#ifdef LOG_ENABLE_ASSERTS
    #define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define LOG_ASSERT(x, ...)
    #define LOG_CORE_ASSERT(x, ...)
#endif

#define BIT(n) (1 << n)

#define BIND_EVENT_FN(fn) std::bind(&fn, this)
#define BIND_EVENT_FN_ONE(fn) std::bind(&fn, this, std::placeholders::_1)