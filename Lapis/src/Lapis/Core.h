#pragma once

#ifdef LP_PLATFORM_WINDOWS
	#ifdef LP_BUILD_DLL
#define LAPIS_API __declspec(dllexport)
	#else
#define LAPIS_API __declspec(dllimport)
	#endif
#else
	#error Lapis only supports Windows!
#endif 
