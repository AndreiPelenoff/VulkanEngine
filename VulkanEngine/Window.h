#ifndef WINDOW
#define WINDOW
#pragma once

#include <string>
#include <SDL_syswm.h>
#include <SDL_vulkan.h>

#include "SDL.h"

class Window
{
public:

    Window(int width, int height, std::string title = "window");

    bool init();
    bool destroy();
    HWND getWindowHwnd();


    ~Window();

    int m_width;
    int m_height;
    std::string m_title;

    bool m_isInit;


    SDL_Window *window;
};


#endif