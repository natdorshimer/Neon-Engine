#include "neon-pch.h"
#include "Window.h"
#include "WinWindow.h"

namespace Neon
{
	Window* Window::Create()
	{
		#ifdef NEON_PLATFORM_WINDOWS
			return new WinWindow();
		#else

		#error 
			Others not supported atm :^)
		#endif

	}
}