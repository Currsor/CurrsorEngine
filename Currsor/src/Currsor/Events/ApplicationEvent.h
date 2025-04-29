#pragma once

#include "Event.h"
 
namespace Currsor {
 
    class CURRSOR_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}
 
        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }
 
        std::string ToString() const override
        {
            std::string a = "WindowResizeEvent: " + std::to_string(GetWidth()) + ", " + std::to_string(GetHeight());
            return a;
        }
 
        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    private:
        unsigned int m_Width, m_Height;
    };
 
    class CURRSOR_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}
 
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
 
    class CURRSOR_API AppTickEvent : public Event
    {
    public:
        AppTickEvent() {}
 
        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
 
    class CURRSOR_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}
 
        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
 
    class CURRSOR_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}
 
        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}