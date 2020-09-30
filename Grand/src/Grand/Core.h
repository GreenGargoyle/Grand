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