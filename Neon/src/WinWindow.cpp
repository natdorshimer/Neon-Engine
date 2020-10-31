#include "neon-pch.h"
#include "Core.h"
#include "WinWindow.h"
#include "GLFW/glfw3.h"
#include <memory>
#include "Events/Event.h"
#include "Log.h"


Neon::WinWindow::WinWindow() : 
	m_Window(nullptr)
{
	Init();
}

void Neon::WinWindow::Init()
{
	if (!glfwInit())
		NEON_DEBUG_ASSERT(false, "GLFW failed to initialize.\n");


	m_WindowData.Width = 640;
	m_WindowData.Height = 480;
	m_WindowData.Title = "Neon Engine";

	m_Window = glfwCreateWindow(m_WindowData.Width, m_WindowData.Height, m_WindowData.Title.c_str(), nullptr, nullptr);


	NEON_DEBUG_ASSERT(m_Window, "m_Window is null");


	glfwMakeContextCurrent(m_Window);

	glfwSetWindowUserPointer(m_Window, &m_WindowData);


	//TODO: Set up the event callbacks
	glfwSetWindowCloseCallback(m_Window, 
		[](GLFWwindow* win)
		{
			WindowData* data = (WindowData*) glfwGetWindowUserPointer(win);

			WindowCloseEvent event;

			data->Callback(event);
		}
	);


	NEON_DEBUG_INFO("Window Initialized\n");
}


void Neon::WinWindow::OnUpdate()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void Neon::WinWindow::Shutdown()
{
	glfwDestroyWindow(m_Window);
}
