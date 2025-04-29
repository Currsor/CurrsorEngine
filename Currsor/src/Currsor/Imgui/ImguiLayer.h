#pragma once
#include "Currsor/Layer.h"
#include "Currsor/Events/MouseEvent.h"

namespace Currsor 
{
    class CURRSOR_API ImGuiLayer : public Currsor::Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        void OnAttach() override; //当layer添加到layer stack的时候会调用此函数，相当于Init函数
        void OnDetach() override; //当layer从layer stack移除的时候会调用此函数，相当于Shutdown函数
        void OnEvent(Event&) override;
        void OnUpdate() override;

    private:
        float m_Time = 0.0f;
        bool OnMouseCursorMoved(MouseMovedEvent& e);
        bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
    };
}
