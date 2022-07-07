#include "window_system.h"

#include <backends/imgui_impl_win32.h>
#include <backends/imgui_impl_dx12.h>
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//#include "runtime/core/base/macro.h"

namespace ToyEngine
{
    WindowSystem::~WindowSystem()
    {
        //glfwDestroyWindow(m_window);
        //glfwTerminate();
      ::DestroyWindow(m_window);
    }

    // Win32 message handler
    LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
      if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

      switch (msg)
      {
      case WM_SIZE:
        /*  if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
          {
            WaitForLastSubmittedFrame();
            CleanupRenderTarget();
            HRESULT result = g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT);
            assert(SUCCEEDED(result) && "Failed to resize swapchain.");
            CreateRenderTarget();
          }*/
        return 0;
      case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
          return 0;
        break;
      case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
      case WM_CLOSE:
        ::DestroyWindow(hWnd);
        return 0;
      }
      return ::DefWindowProc(hWnd, msg, wParam, lParam);
    }

    void WindowSystem::initialize(WindowCreateInfo create_info)
    {
        //if (!glfwInit())
        //{
        //   // LOG_FATAL(__FUNCTION__, "failed to initialize GLFW");
        //    return;
        //}

        m_width  = create_info.width;
        m_height = create_info.height;

         //¸Ä³ÉD3dµÄAPI
        WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, L"ToyEngine", NULL };
        ::RegisterClassEx(&wc);
        HWND m_window = ::CreateWindow(wc.lpszClassName, L"ToyEngine", WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);


        //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        //m_window = glfwCreateWindow(create_info.width, create_info.height, create_info.title, nullptr, nullptr);
        if (!m_window)
        {
           // LOG_FATAL(__FUNCTION__, "failed to create window");
            return;
        }

        // Show the window
        ::ShowWindow(m_window, SW_SHOWDEFAULT);
        ::UpdateWindow(m_window);

        //// Setup input callbacks
        //glfwSetWindowUserPointer(m_window, this);
        //glfwSetKeyCallback(m_window, keyCallback);
        //glfwSetCharCallback(m_window, charCallback);
        //glfwSetCharModsCallback(m_window, charModsCallback);
        //glfwSetMouseButtonCallback(m_window, mouseButtonCallback);
        //glfwSetCursorPosCallback(m_window, cursorPosCallback);
        //glfwSetCursorEnterCallback(m_window, cursorEnterCallback);
        //glfwSetScrollCallback(m_window, scrollCallback);
        //glfwSetDropCallback(m_window, dropCallback);
        //glfwSetWindowSizeCallback(m_window, windowSizeCallback);
        //glfwSetWindowCloseCallback(m_window, windowCloseCallback);

        //glfwSetInputMode(m_window, GLFW_RAW_MOUSE_MOTION, GLFW_FALSE);
    }

    void WindowSystem::pollEvents() const {/* glfwPollEvents();*/ }

    bool WindowSystem::shouldClose() const { return false;/*return glfwWindowShouldClose(m_window);*/ }

    void WindowSystem::setTile(const char* title) {/* glfwSetWindowTitle(m_window, title);*/ }

    HWND WindowSystem::getWindow() const { return m_window; }

    std::array<int, 2> WindowSystem::getWindowSize() const { return std::array<int, 2>({m_width, m_height}); }

    void WindowSystem::setFocusMode(bool mode)
    {
        m_is_focus_mode = mode;
       // glfwSetInputMode(m_window, GLFW_CURSOR, m_is_focus_mode ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
    }
} // namespace ToyEngine
