#pragma once
 
#include "PCH.h"
 
#include "Currsor/Core.h"
#include "Currsor/Events/Event.h"
 
namespace Currsor {
 
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;
 
        WindowProps(const std::string& title = "Currsor",
                    unsigned int width = 1280,
                    unsigned int height = 720)
            : Title(title), Width(width), Height(height)
        {}
    };
 
    // 界面代表桌面系统基于窗口
    class CURRSOR_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
 
        virtual ~Window() {}
 
        virtual void OnUpdate() = 0;
 
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
 
        // 窗口的属性
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;
 
        static Window* Create(const WindowProps& props = WindowProps());
    };
 
}