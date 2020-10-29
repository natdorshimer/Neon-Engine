#include "neon-pch.h"
#include "Application.h"
#include "Window.h"

namespace Neon
{

	Neon::Application::Application()
	{
		m_Window.reset(Window::Create());
	}

	void Neon::Application::Run()
	{
		while (m_Window.get())
		{
			m_Window->OnUpdate();
		}
	}

	void Neon::Application::Shutdown()
	{
		m_Window->Shutdown();
	}
}
