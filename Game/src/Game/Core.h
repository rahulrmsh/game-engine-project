#pragma once
#ifndef GAME_PLATFORM_WINDOWS
	#ifndef GAME_BUILD_DLL
		#define Game_API __declspec(dllexport)
	#else
		#define Game_API __declspec(dllimport)
	#endif // !GAME_BUILD_DLL
#else
	#error Game is supported only in Windows!
#endif // !GAME_PLATFORM_WINDOWS

