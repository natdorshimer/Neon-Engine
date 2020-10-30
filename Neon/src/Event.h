#pragma once
#include "MouseCodes.h"
#include "KeyCodes.h"
#include <string>
#include <sstream>

#define EVENT_CATEGORY(x) \
	inline int GetCategory() const override { return EventCategory::##x; } \
	inline bool IsCategory(EventCategory cat) const override { return GetCategory() & cat; } 
#define EVENT_TYPE(x) \
	inline std::string GetName() const override { return #x ; } \
	inline EventType GetType() const override { return EventType::##x ; } \
	inline bool IsEventType(EventType e) const override { return GetType() & e; } 

namespace Neon
{
	enum EventType
	{
		MousePressedEvent, MouseReleasedEvent, MouseRepeatEvent, MouseMovedEvent, MouseScrollEvent,
		KeyPressedEvent, KeyReleasedEvent, KeyRepeatEvent,
		WindowCloseEvent, WindowResizeEvent
	};

	enum EventCategory
	{
		MouseEvent,
		KeyboardEvent,
		InputEvent,
		ApplicationEvent
	};

	class EventDispatcher
	{

	};

	class Event
	{
	public:

		//Returns the combination of event categories the event has
		virtual int GetCategory() const = 0;

		//Returns true if it has an EventCategory flag for cat
		virtual bool IsCategory(EventCategory cat) const = 0;

		//Returns the name of the specific type of event
		virtual std::string GetName() const = 0;

		//Returns the type flag of the event (ex MousePressedEvent)
		virtual EventType GetType() const = 0;

		//Returns true if the type matches e
		virtual bool IsEventType(EventType e) const = 0;

		//Returns a string detailing the event. For debug purposes
		inline virtual std::string ToString() const { return GetName(); }
	};

	class WindowCloseEvent : public Event
	{
	public:
		EVENT_TYPE(WindowCloseEvent)

		EVENT_CATEGORY(ApplicationEvent)
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int width, int height) :
			m_Width(width), m_Height(height)
		{

		}

		inline std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << std::endl;
			ss << "Width: " << m_Width << std::endl;
			ss << "Height: " << m_Height << std::endl;

			return ss.str();
		}

		EVENT_TYPE(WindowResizeEvent)

		EVENT_CATEGORY(ApplicationEvent)
	private:
		int m_Width;
		int m_Height;
	};
}

