#include "neon-pch.h"
#include "WinWindow.h"
#include "Core.h"
#include "GLFW/glfw3.h"
#include <memory>
#include "Event.h"


Neon::WinWindow::WinWindow() : 
	m_Window(nullptr)
{
	Init();
}

void Neon::WinWindow::Init()
{
	if (!glfwInit())
		NEON_ASSERT(false);

	m_Window = glfwCreateWindow(640, 480, "Neon Engine", nullptr, nullptr);

	NEON_ASSERT(m_Window);


	glfwMakeContextCurrent(m_Window);

	glfwSetWindowUserPointer(m_Window, &m_WindowData);

	glfwSetWindowCloseCallback(m_Window, 
		[](GLFWwindow* win)
		{
			WindowData* data = (WindowData*) glfwGetWindowUserPointer(win);

			//TODO: propagate the event towards application

			glfwDestroyWindow(win);
		}
	);
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
