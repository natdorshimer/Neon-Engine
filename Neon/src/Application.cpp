#include "neon-pch.h"
#include "Application.h"
#include "Window.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
namespace Neon
{

	Application::Application() : m_Running(true)
	{
		m_Window.reset(Window::Create());

		//Bind the application's OnUpdate as the event handler for the window itself
		m_Window->SetEventCallback([this](Event& e){this->OnEvent(e); });
	}

	void Application::Run()
	{
		static Clock clk;

		Timestep dt = clk.GetElapsedTime();
		clk.Reset();

		while (m_Running)
		{
			m_Window->OnUpdate();

			m_LayerStack.OnUpdate(dt);
		}
	}

	//This is where application event handling is dealt with 
	void Application::OnEvent(Event& e)
	{
		auto shutdown = [this](Event& e)->bool { this->Shutdown(); return true; };
		auto keyHandler = [](Event& e)->bool { return true; };

		EventDispatcher ed(e);

		m_LayerStack.OnEvent(e);
	}

	void Neon::Application::Shutdown()
	{
		m_Running = false;
		m_Window->Shutdown();
	}
}
