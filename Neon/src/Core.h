#pragma once
#include <assert.h>

#ifdef NEON_DLL
	#define NEON_API __declspec(dllexport)
#else
	#define NEON_API __declspec(dllimport)
#endif


//TODO: make the asserts more meaningful 
#ifdef NEON_DEBUG
	#define NEON_DEBUG_BREAK() NEON_DEBUG_CRITICAL("Ending program.\n"); assert(false); 

	#define NEON_DEBUG_ASSERT(x, msg) \
		if(!x) \
		{ \
			NEON_DEBUG_CRITICAL("Assertion failure: {}\n", msg); \
			NEON_DEBUG_BREAK(); \
		} 
#else
	#define NEON_DEBUG_ASSERT(x, msg) 
	#define NEON_DEBUG_BREAK();
#endif