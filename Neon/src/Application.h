#pragma once

#include "Core.h"
#include "Window.h"

namespace Neon
{
	class NEON_API Application
	{
	public:
		Application();

		virtual void Shutdown();

		virtual void Run();

		virtual void OnUpdate(Event& fn);

	private:
		std::shared_ptr<Window> m_Window;
	};
}