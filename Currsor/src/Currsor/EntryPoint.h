#pragma once

#include "../Currsor.h"

#ifdef CS_PLATFORM_WINDOWS

extern Currsor::Application* CreateApplication(int argc, char** argv);

int main(int argc, char** argv)
{
    Currsor::Log::Init();
    
    auto app = CreateApplication(argc, argv);
    app->Run();
    delete app;
}

#else
    #error Currsor only supports Windows!
#endif