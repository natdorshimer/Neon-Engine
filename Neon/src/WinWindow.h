#pragma once
#include "Window.h"
#include "GLFW/glfw3.h"

namespace Neon
{
	class WinWindow : public Window
	{
	public:
		WinWindow();
		virtual void OnUpdate() override;

		virtual void Shutdown() override;

	private:
		GLFWwindow* m_Window;
	};
}