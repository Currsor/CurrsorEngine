#include <Currsor.h>

class Sandbox : public Currsor::Application
{
public:
    Sandbox()
    {
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