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

#ifdef LP_ENABLE_ASSERTS
	#define LP_ASSERT(x, ...) { if(!(x)) { LP_ERROR("Assertion Failed: {0}", __VA_ARGS__);; __debugbreak(); } }
	#define LP_CORE_ASSERT(x, ...) { if(!(x)) { LP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);; __debugbreak(); } }
#else
	#define LP_ASSERT(x, ...)
	#define LP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
