#pragma once

#include "PCH.h"

#include "Event.h"

namespace Currsor
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float m_x_offset, float m_y_offset)
            : m_xOffset(m_x_offset),
              m_yOffset(m_y_offset){}
        
        float GetXOffset() const { return m_xOffset; }
        float GetYOffset() const { return m_yOffset; }
        
        std::string ToString() const override
        {
            // 创建一个带有表示的字符串
            std::string a = "MouseMovedEvent: xOffset = " + std::to_string(GetXOffset()) + ", yOffset = " + std::to_string(GetYOffset());
            return a;
        }
        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_xOffset, m_yOffset;
    };

    class CURRSOR_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
             : m_XOffset(xOffset), m_YOffset(yOffset) {}
 
        inline float GetXOffset() const { return m_XOffset; }
        inline float GetYOffset() const { return m_YOffset; }
 
        std::string ToString() const override
        {
            // 创建一个带有表示的字符串
            std::string a = "MouseMovedEvent: xOffset = " + std::to_string(GetXOffset()) + ", yOffset = " + std::to_string(GetYOffset());
            return a;
        }
 
        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_XOffset, m_YOffset;
    };
 
    class CURRSOR_API MouseButtonEvent : public Event
    {
    public:
        inline int GetMouseButton() const { return m_Button; }
 
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseButtonEvent(int button)
            : m_Button(button) {}
 
        int m_Button;
    };
 
    class CURRSOR_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}
 
        std::string ToString() const override
        {
            std::string a = "MouseButtonPressedEvent: " + std::to_string(m_Button);
            return a;
        }
 
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };
 
    class CURRSOR_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) {}
 
        std::string ToString() const override
        {
            std::string a = "MouseButtonReleasedEvent: " + std::to_string(m_Button);
            return a;
        }
 
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}
