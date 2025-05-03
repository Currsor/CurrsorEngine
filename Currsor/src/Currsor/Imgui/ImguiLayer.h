#pragma once

#include "Currsor/Layer.h"
#include "Currsor/Events/ApplicationEvent.h"

namespace Currsor 
{
    class Application;

    class CURRSOR_API ImGuiLayer : public Currsor::Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override;
        void OnAttach() override; //当layer添加到layer stack的时候会调用此函数，相当于Init函数
        void OnDetach() override; //当layer从layer stack移除的时候会调用此函数，相当于Shutdown函数
        void OnImGuiRender() override;
 
        void Begin();
        void End();

    private:
        float m_Time = 0.0f;
    };
}
