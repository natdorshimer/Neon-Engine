#include "neon-pch.h"
#include "Application.h"
#include "Window.h"

namespace Neon
{

	Application::Application()
	{
		m_Window.reset(Window::Create());

		//Bind the application's OnUpdate as the event handler for the window itself
		m_Window->SetEventCallback([this](Event& e){this->OnUpdate(e); });
	}

	void Application::Run()
	{
		while (m_Window.get())
		{
			m_Window->OnUpdate();
		}
	}

	//This is where application event handling is dealt with 
	void Application::OnUpdate(Event& e)
	{
		auto shutdown = [this](Event& e)->bool { this->Shutdown(); return true; };

		EventDispatcher ed(e);
		ed.Dispatch<WindowCloseEvent>(shutdown);
	}

	void Neon::Application::Shutdown()
	{
		m_Window->Shutdown();
	}
}
