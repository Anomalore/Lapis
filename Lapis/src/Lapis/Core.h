#pragma once

#ifdef LP_PLATFORM_WINDOWS
	#ifdef LP_BUILD_DLL
		#define LAPIS_API __declspec(dllexport)
	#else
		#define LAPIS_API __declspec(dllimport)
	#endif
	#ifdef LP_ENABLE_ASSERTS
		#define LP_ASSERT(x, ...) { if(!(x)) { LP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
		#define LP_CORE_ASSERT(x, ...) { if(!(x)) { LP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#else
		#define LP_ASSERT(x, ...)
		#define LP_CORE_ASSERT(x, ...)
	#endif
#else
	#define LAPIS_API
	#ifdef LP_ENABLE_ASSERTS
		#define LP_ASSERT(x, ...) { if(!(x)) { LP_ERROR("Assertion Failed: {0}", __VA_ARGS__); } }
		#define LP_CORE_ASSERT(x, ...) { if(!(x)) { LP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); } }
	#else
		#define LP_ASSERT(x, ...)
		#define LP_CORE_ASSERT(x, ...)
	#endif
#endif 

#ifdef LP_DEBUG
	#define LP_ENABLE_ASSERTS
#endif


#define BIT(x) (1 << x)

#define LP_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
