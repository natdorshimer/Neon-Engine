#pragma once
#include "neon-pch.h"
#include "Event.h"
#include "Core.h"
#include <sstream>


namespace Neon
{
	class KeyEvent : public Event
	{
	public:
		KeyEvent() = delete;

		inline virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << ":   MouseCode:" << m_KeyCode;
			return ss.str();
		}

		virtual std::string GetName() const = 0;

		EVENT_CATEGORY(Keyboard)

	protected:
		KeyEvent(KeyCode key) : m_KeyCode(key) { }

		KeyCode m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode key) : KeyEvent(key) { }

		EVENT_TYPE(KeyPressedEvent)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KeyCode key) : KeyEvent(key) { }

		EVENT_TYPE(KeyReleasedEvent)
	};

	class KeyRepeatEvent : public KeyEvent
	{
	public:
		KeyRepeatEvent(KeyCode key) : KeyEvent(key) { }

		EVENT_TYPE(KeyRepeatEvent)
	};
}