#pragma once

#include "Currsor/Core.h"

namespace Currsor
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, //窗口的五种操作，0x001,0x010,0x011,0x100,0x
        AppTick, AppUpdate, AppRender,                                        //APP的操作，暂时先不计较这个
        KeyPressed, KeyReleased,                                              //键盘的两种操作
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled    //鼠标的四种操作
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

    
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
                              virtual EventType GetEventType() const override { return GetStaticType(); }\
                              virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class CURRSOR_API Event
    {
        friend class EventDispatcher;
    public:
        virtual ~Event() = default;

        bool Handled = false;
        
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& event)
            : m_Event(event)
        {
        }
 
        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };
 
    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}
