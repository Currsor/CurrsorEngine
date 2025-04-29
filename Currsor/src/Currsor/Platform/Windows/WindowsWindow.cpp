#include "PCH.h"
#include "WindowsWindow.h"

#include "Currsor/Events/ApplicationEvent.h"
#include "Currsor/Events/MouseEvent.h"
#include "Currsor/Events/KeyEvent.h"

namespace Currsor {
 	
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char* description)
    {
        LOG_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }
 
    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }
 
    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        WindowsWindow::Init(props);
    }
 
    WindowsWindow::~WindowsWindow()
    {
        WindowsWindow::Shutdown();
    }
 
    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;
 
        LOG_CORE_TRACE("创建窗口 {0} ({1}, {2})", props.Title, props.Width, props.Height);
 
        if (!s_GLFWInitialized)
        {
            // TODO: 在系统关闭时终止 GLFW
            int success = glfwInit();
            LOG_CORE_ASSERT(success, "无法初始化 GLFW!");

            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }
 
        m_Window = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height), m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        // 设置GLFW回调
 		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
 		{
 			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
 			data.Width = width;
 			data.Height = height;
 
 			WindowResizeEvent event(width, height);
 			data.EventCallback(event);
 		});
 
 		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
 		{
		    const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
 			WindowCloseEvent event;
 			data.EventCallback(event);
 		});
 
 		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
 		{
		    const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
 
 			switch (action)
 			{
 				case GLFW_PRESS:
 				{
 					KeyPressedEvent event(key, 0);
 					data.EventCallback(event);
 					break;
 				}
 				case GLFW_RELEASE:
 				{
 					KeyReleasedEvent event(key);
 					data.EventCallback(event);
 					break;
 				}
 				case GLFW_REPEAT:
 				{
 					KeyPressedEvent event(key, 1);
 					data.EventCallback(event);
 					break;
 				}
		    default: break;
		    }
 		});
 
 		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
 		{
		    const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
 
 			switch (action)
 			{
 				case GLFW_PRESS:
 				{
 					MouseButtonPressedEvent event(button);
 					data.EventCallback(event);
 					break;
 				}
 				case GLFW_RELEASE:
 				{
 					MouseButtonReleasedEvent event(button);
 					data.EventCallback(event);
 					break;
 				}
		    default: break;
		    }
 		});
 
 		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
 		{
		    const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
 
 			MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
 			data.EventCallback(event);
 		});
 
 		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
 		{
		    const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
 
 			MouseMovedEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
 			data.EventCallback(event);
 		});
    }
 
    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }
 
    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
 
    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
 
        m_Data.VSync = enabled;
    }
 
    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }
 
}
