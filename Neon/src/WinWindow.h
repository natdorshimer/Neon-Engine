#pragma once
#include "Window.h"
#include "GLFW/glfw3.h"

namespace Neon
{
	class WinWindow : public Window
	{
	public:
		WinWindow();

		virtual void Init();

		virtual void OnUpdate() override;

		virtual void Shutdown() override;

	private:

		void InitInputHandlers();

	private:
		GLFWwindow* m_Window;

	};
}