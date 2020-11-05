#pragma once

#ifdef GRAND_PLATFORM_WINDOWS
	#ifdef GRAND_BUILD_DLL
		#define GRAND_API __declspec(dllexport)
	#else
		#define GRAND_API __declspec(dllimport)
	#endif
#else
	#error Grand only supports Windows!
#endif

#ifdef GRAND_ENABLE_ASSERTS
	#define GRAND_ASSERT(x, ...) { if (!(x)) {GRAND_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GRAND_CORE_ASSERT(x, ...) { if (!(x)) {GRAND_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GRAND_ASSERT(x, ...)
	#define GRAND_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)