#pragma once
#include "neon-pch.h"
#include "Event.h"
#include "Core.h"
#include <sstream>

namespace Neon
{
	class NEON_API MouseEvent : public Event
	{
	public:
		MouseEvent() = delete;

		inline virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << ":   MouseCode:" << m_Button;
			return ss.str();
		}

		virtual std::string GetName() const = 0;

		virtual MouseCode GetMouseCode() { return m_Button; }

		EVENT_CATEGORY(MouseEvent | InputEvent)

	protected:
		MouseEvent(MouseCode mousecode);

		MouseCode m_Button;
	};


	class NEON_API MousePressedEvent : public MouseEvent
	{
	public:
		MousePressedEvent(MouseCode code) : MouseEvent(code) {}

		EVENT_TYPE(MousePressed)
	};


	class NEON_API MouseReleasedEvent : public MouseEvent
	{
	public:
		MouseReleasedEvent(MouseCode code) : MouseEvent(code) {}

		EVENT_TYPE(MouseReleased)
	};


	class NEON_API MouseRepeatEvent : public MouseEvent
	{
	public:
		MouseRepeatEvent(MouseCode code) : MouseEvent(code) {}

		EVENT_TYPE(MouseReleased)
	};


	class NEON_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float xoffset, float yoffset) :
			m_xOffset(xoffset), m_yOffset(yoffset)
		{

		}

		inline virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << std::endl;
			ss << "xOffset: " << m_xOffset << std::endl;
			ss << "yOffset: " << m_yOffset << std::endl;

			return ss.str();
		}

		float GetXOffset() { return m_xOffset; }
		float GetYOffset() { return m_xOffset; }

		EVENT_TYPE(MouseReleased)
		EVENT_CATEGORY(MouseEvent | InputEvent)

	private:
		float m_xOffset;
		float m_yOffset;
	};


	class NEON_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float xpos, float ypos) :
			m_xPos(xpos), m_yPos(ypos)
		{

		}

		inline virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << std::endl;
			ss << "xPos: " << m_xPos << std::endl;
			ss << "yPos: " << m_yPos << std::endl;
			
			return ss.str();
		}

		EVENT_TYPE(MouseMoved)
		EVENT_CATEGORY(MouseEvent | InputEvent)

	private:
		float m_xPos;
		float m_yPos;
	};

}