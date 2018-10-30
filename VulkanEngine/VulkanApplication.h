#ifndef VULKAN_APPLICATION
#define VULKAN_APPLICATION
#pragma once

#include "Application.h"
#include "Window.h"
#include "VulkanSystem.h"

class VulkanApplication: Application
{
public:
    VulkanApplication(std::string application_name, uint32_t width, uint32_t height);

    bool run();

    bool mainLoop();

    ~VulkanApplication();

    Window* m_window;
    VulkanSystem* m_vulkanSystem;
};

#endif