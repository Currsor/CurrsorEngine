#pragma once

#include "Core.h"
#include "Window.h"

#include "Currsor/LayerStack.h"
#include "Events/ApplicationEvent.h"

namespace Currsor
{
    // 显式实例化并导出
    template class CURRSOR_API std::unique_ptr<Window>;
    
    class CURRSOR_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        Window& GetWindow() { return *m_Window; }

        static Application& Get() { return *s_Instance; }
        
        Application* CreateApplication(int argc, char** argv);


    private:
        bool OnWindowClose(WindowCloseEvent& e);
        
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        static Application* s_Instance;
    };
    
}

