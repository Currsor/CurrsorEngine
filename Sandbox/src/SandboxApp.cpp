#include <Currsor.h>

class ExampleLayer : public Currsor::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }
 
    void OnUpdate() override
    {
        // LOG_TRACE("ExampleLayer::Update");
    }
 
    void OnEvent(Currsor::Event& event) override
    {
        // LOG_INFO("{0}", event.ToString());
    }
 
};

class Sandbox : public Currsor::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Currsor::ImGuiLayer());
    }
    ~Sandbox() override
    {
    }
    
};

Currsor::Application* CreateApplication(int argc, char** argv)
{
    SetConsoleOutputCP(65001);  // 设置控制台输出编码为 UTF-8 
    return new Sandbox();
}