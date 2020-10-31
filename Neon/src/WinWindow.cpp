#include "neon-pch.h"
#include "Core.h"
#include "WinWindow.h"
#include "Window.h"
#include "GLFW/glfw3.h"
#include <memory>
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
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

	InitInputHandlers();

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

void Neon::WinWindow::InitInputHandlers()
{
	//TODO: Set up the event callbacks
	glfwSetWindowCloseCallback(m_Window,
		[](GLFWwindow* win)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);

			WindowCloseEvent event;

			data->Callback(event);
		}
	);

	glfwSetKeyCallback(m_Window,
		[](GLFWwindow* win, int key, int scancode, int action, int mods)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
			KeyCode keyCode = KeyCode(key);

			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent e{ keyCode };
				data->Callback(e);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent e{ keyCode };
				data->Callback(e);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyRepeatEvent e{ keyCode };
				data->Callback(e);
				break;
			}
			}

		}
	);

	glfwSetMouseButtonCallback(m_Window,
		[](GLFWwindow* win, int button, int action, int mods)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
			MouseCode keyCode = MouseCode(action);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MousePressedEvent e{ keyCode };
				data->Callback(e);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseReleasedEvent e{ keyCode };
				data->Callback(e);
				break;
			}
			case GLFW_REPEAT:
			{
				MouseRepeatEvent e{ keyCode };
				data->Callback(e);
				break;
			}
			}
		}
	);

	glfwSetWindowSizeCallback(m_Window,
		[](GLFWwindow* win, int width, int height)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);
			data->Width = width;
			data->Height = height;

			WindowResizeEvent e{ width, height };
			data->Callback(e);
		}
	);

	glfwSetScrollCallback(m_Window,
		[](GLFWwindow* win, double xoffset, double yoffset)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(win);

			MouseScrollEvent e{ (float)xoffset, (float)yoffset };
			data->Callback(e);
		}
	);
}
