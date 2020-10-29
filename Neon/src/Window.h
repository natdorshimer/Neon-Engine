#pragma once
#include "Event.h"
#include <memory>

namespace Neon
{
	class Window
	{
	public:
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual void Shutdown() = 0;

		static Window* Create();

	private:

	};
}

