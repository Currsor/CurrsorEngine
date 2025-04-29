#pragma once

#include "Core.h"
#include "Window.h"
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
        void OnEvent(Event& e);

        Application* CreateApplication(int argc, char** argv);

        void Run();
        bool OnWindowClose(WindowCloseEvent& e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
    
}

