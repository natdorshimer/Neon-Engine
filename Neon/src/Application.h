#pragma once

#include "Core.h"
#include "Window.h"

namespace Neon
{
	class NEON_API Application
	{
	public:
		Application();

		void Shutdown();

		void Run();

	private:
		std::shared_ptr<Window> m_Window;

	};
}