#include "neon-pch.h"
#include "WinWindow.h"
#include "Core.h"
#include "GLFW/glfw3.h"
#include <memory>

Neon::WinWindow::WinWindow()
{
	if (!glfwInit())
		NEON_ASSERT(false);

	m_Window = glfwCreateWindow(640, 480, "Neon Engine", nullptr, nullptr);

	NEON_ASSERT(m_Window);

	glfwMakeContextCurrent(m_Window);
}

void Neon::WinWindow::OnUpdate()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void Neon::WinWindow::Shutdown()
{

}
