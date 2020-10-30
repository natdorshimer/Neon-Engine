#pragma once
#include "neon-pch.h"
#include "Log.h"
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
	inline static EventType GetStaticType() { return EventType::##x ;} \
	inline bool IsEventType(EventType e) const override { return GetType() & e; } 

namespace Neon
{

	enum EventType
	{
		MousePressed, MouseReleased, MouseRepeat, MouseMoved, MouseScroll,
		KeyPressed, KeyReleased, KeyRepeat,
		WindowClose, WindowResize
	};

	enum EventCategory
	{
		MouseEvent,
		KeyboardEvent,
		InputEvent,
		ApplicationEvent
	};



	class NEON_API Event
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


	class NEON_API EventDispatcher
	{
	public:
		EventDispatcher(Event& e) :
			m_Event(e), m_Handled(false)
		{

		}

		// Attempts to dispatch an event for type Event_T
		// Will not dispatch unless the type of m_Event and the given event match
		template<typename Event_T>
		void Dispatch(const std::function<bool(Event&)>& handler)
		{
			if (m_Event.GetType() == Event_T::GetStaticType())
			{
				m_Handled = handler(m_Event);

				NEON_DEBUG_INFO("{}\n", m_Event.ToString());
			}
		}

		bool IsHandled() { return m_Handled; }
	private:
		Event& m_Event;
		bool m_Handled;
	};

	class NEON_API WindowCloseEvent : public Event
	{
	public:
		EVENT_TYPE(WindowClose)

		EVENT_CATEGORY(ApplicationEvent)
	};

	class NEON_API WindowResizeEvent : public Event
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

		EVENT_TYPE(WindowResize)

		EVENT_CATEGORY(ApplicationEvent)

	private:
		int m_Width;
		int m_Height;
	};
}

