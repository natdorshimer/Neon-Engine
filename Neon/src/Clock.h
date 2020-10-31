#pragma once

#include "neon-pch.h"
#include <chrono>

namespace Neon
{
	//Clock implementation can vary by platform
	//TODO: Currently not a great implementation
	namespace 
	{
	#ifdef NEON_PLATFORM_WINDOWS
		using TimePoint = std::chrono::steady_clock::time_point;
	#else
		using TimePoint = std::chrono::system_clock::time_point;
	#endif
	}

	struct Timestep
	{
		using TimeDiff = std::chrono::steady_clock::duration;
		TimeDiff m_Timestep;

		//Returns the timestep in milliseconds
		inline double AsMilliseconds()
		{
			return std::chrono::duration<double>(m_Timestep).count()*1000;
		}

		//Returns the timestep in seconds
		inline double AsSeconds()
		{
			return std::chrono::duration<double>(m_Timestep).count();
		}

		//Returns the timestep in microseconds
		inline double AsMicroseconds()
		{
			return AsMilliseconds() * 1000;
		}
	};

	//TODO: not necessarily great cross-platform
	//Acts as a very basic clock that can return elapsed time since its last reset.
	class Clock
	{
		using ChronoClock = std::chrono::high_resolution_clock;

	public:

		inline void Start()  { m_StartTime = ChronoClock::now(); }
		
		inline void Reset() { Start(); }

		inline Timestep GetElapsedTime() const
		{
			return { ChronoClock::now() - m_StartTime };
		}

	private:
		TimePoint m_StartTime;
	};
}