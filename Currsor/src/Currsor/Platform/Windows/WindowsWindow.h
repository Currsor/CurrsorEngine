#pragma once
 
#include "PCH.h"

#include "Currsor/Window.h"
#include "GLFW/glfw3.h"

namespace Currsor {
 
 	class WindowsWindow : public Window
 	{
 	public:
 		WindowsWindow(const WindowProps& props);
	    ~WindowsWindow() override;
 
 		void OnUpdate() override;

	    unsigned int GetWidth() const override { return m_Data.Width; }
	    unsigned int GetHeight() const override { return m_Data.Height; }
 
 		// 窗口的属性
	    void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
 		void SetVSync(bool enabled) override;
 		bool IsVSync() const override;
 	private:
 		virtual void Init(const WindowProps& props);
 		virtual void Shutdown();

 		GLFWwindow* m_Window;
 
 		struct WindowData
 		{
 			std::string Title;
 			unsigned int Width, Height;
 			bool VSync;
 
 			EventCallbackFn EventCallback;
 		};
 
 		WindowData m_Data;
 	};
 
}
