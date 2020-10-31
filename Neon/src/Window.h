#pragma once
#include "Events/Event.h"
#include <memory>
#include "neon-pch.h"
namespace Neon
{
	using EventCallbackFn = std::function<void(Event&)>;


	struct WindowData
	{
		unsigned int Width;
		unsigned int Height;
		std::string Title;

		EventCallbackFn Callback;
	};

	class Window
	{
	public:
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual void Shutdown() = 0;

		//This is so that you can control what happens on-event application side
		virtual void SetEventCallback(const EventCallbackFn& callback);

		static Window* Create();

	protected:
		WindowData m_WindowData;
	};
}

