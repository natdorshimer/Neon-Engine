#pragma once

#include "neon-pch.h"
#include "Core.h"
#include "Window.h"
#include "LayerStack.h"

namespace Neon
{
	class NEON_API Application
	{
	public:
		Application();

		virtual void Shutdown();

		virtual void Run();

		virtual void OnEvent(Event& fn);

	private:
		std::shared_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running;
	};


}