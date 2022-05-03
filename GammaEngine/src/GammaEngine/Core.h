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

#define BIT(x) (1 << x)