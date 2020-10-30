#pragma once
#include "Event.h"
#include <memory>

namespace Neon
{
	struct WindowData
	{
		unsigned int Width;
		unsigned int Height;
	};

	class Window
	{
	public:
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual void Shutdown() = 0;

		static Window* Create();

	protected:
		WindowData m_WindowData;
	};
}

