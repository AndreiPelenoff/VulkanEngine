#include "Window.h"

Window::Window(int width, int height, std::string title) :m_width(width), m_height(height), m_title(title)
{
    window = nullptr;
    m_isInit = false;

    init();
}

bool Window::init()
{
    if (m_isInit)
    {
        return true;
    }

    SDL_Init(SDL_INIT_VIDEO);
    int res = SDL_Vulkan_LoadLibrary("libvulkan - 1.dll");
    window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_VULKAN);

    if (window)
    {
        m_isInit = true;

        return true;
    }

    return false;
}

bool Window::destroy()
{
    if (!m_isInit)
    {
        return true;
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    delete window;

    m_isInit = false;

    return true;
}

HWND Window::getWindowHwnd()
{
    SDL_SysWMinfo info;
    SDL_VERSION(&info.version);
    SDL_GetWindowWMInfo(window, &info);

    return info.info.win.window;
}

Window::~Window()
{
    SDL_DestroyWindow(window);

    SDL_Quit();

    delete window;

    m_isInit = false;
}



