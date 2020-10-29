#pragma once
#include <assert.h>

#ifdef NEON_DLL
	#define NEON_API __declspec(dllexport)
#else
	#define NEON_API __declspec(dllimport)
#endif


//TODO: make the asserts more meaningful 
#ifdef NEON_DEBUG
	#define NEON_ASSERT(x) assert(x)
#else
	#define NEON_ASSERT(x) 
#endif