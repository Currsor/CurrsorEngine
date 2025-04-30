#pragma once

#include "PCH.h"

#include "Event.h"
#include "../Core/KeyCodes.h"

namespace Currsor
{
    class CURRSOR_API KeyEvent : public Event
    {
    public:
        KeyCode GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode)
            : m_KeyCode(keycode) {}

        KeyCode m_KeyCode;
    };

    class CURRSOR_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override
        {
            std::string a = "KeyPressedEvent: " + std::to_string(GetKeyCode()) + " (" + std::to_string(GetRepeatCount()) + " repeats)";
            return a;
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int m_RepeatCount;
    };

    class CURRSOR_API  KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode)
            : KeyEvent(keycode) {}
 
        std::string ToString() const override
        {
            std::string a = "KeyReleasedEvent: " + std::to_string(GetKeyCode());
            return a;
        }
 
        EVENT_CLASS_TYPE(KeyReleased)
    };

    class CURRSOR_API KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(int keycode)
            : KeyEvent(keycode) {}
 
        std::string ToString() const override
        {
            std::string a = "KeyTypedEvent: " + std::to_string(GetKeyCode());
            return a;
        }
 
        EVENT_CLASS_TYPE(KeyTyped)
    };
}