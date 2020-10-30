#pragma once
#include <cstdarg>
#include <spdlog/spdlog.h>
#include "Core.h"

namespace Neon
{
	class NEON_API Log
	{
	public:
		template<typename... Args>
		inline static void Error(Args&&... args)
		{
			spdlog::error(std::forward<Args>(args)...);
		}

		template<typename... Args>
		inline static void Warn(Args&&... args)
		{
			spdlog::warn(std::forward<Args>(args)...);
		}

		template<typename... Args>
		inline static void Critical(Args&&... args)
		{
			spdlog::critical(std::forward<Args>(args)...);
		}

		template<typename... Args>
		inline static void Info(Args&&... args)
		{
			spdlog::info(std::forward<Args>(args)...);
		}
	};

	#ifdef NEON_DEBUG
		#define NEON_DEBUG_INFO(...) Log::Info(__VA_ARGS__)
		#define NEON_DEBUG_WARN(...) Log::Warn(__VA_ARGS__)
		#define NEON_DEBUG_CRITICAL(...) Log::Critical(__VA_ARGS__)
		#define NEON_DEBUG_ERROR(...) Log::Error(__VA_ARGS__)
	#else
		#define NEON_DEBUG_INFO(...) 
		#define NEON_DEBUG_WARN(...) 
		#define NEON_DEBUG_CRITICAL(...) 
		#define NEON_DEBUG_ERROR(...) 
	#endif
}