#include "neon-pch.h"
#include "Window.h"
#include "WinWindow.h"

namespace Neon
{
	//This is so that you can control what happens on-event application side

	void Window::SetEventCallback(const EventCallbackFn& callback)
	{
		m_WindowData.Callback = callback;
	}

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