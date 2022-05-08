#pragma once

#ifdef GAMMAENGINE_PLATFORM_WINDOWS
	#ifdef GAMMAENGINE_BUILD_DLL
		#define GAMMAENGINE_API __declspec(dllexport)
	#else
		#define GAMMAENGINE_API __declspec(dllimport)
	#endif // GAMMAENGINE_BUILD_DLL
#else
	#error Gamma Engine only supports Windows!!!
#endif 

#ifdef GAMMAENGINE_ENABLE_ASSERTS
	#define GAMMAENGINE_ASSERT(x, ...) { if(!(x)) { GAMMAENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GAMMAENGINE_CORE_ASSERT(x, ...) { if(!(x)) { GAMMAENGINE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GAMMAENGINE_ASSERT(x, ...)
	#define GAMMAENGINE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)