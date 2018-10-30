#ifndef VULKAN_SYSTEM
#define VULKAN_SYSTEM
#pragma once

#include "Window.h"

#include "VulkanElement.h"

#include "VulkanInstance.h"

class VulkanSystem : VulkanElement
{
public:
    VulkanSystem();

    VulkanSystem(Window* window, std::string application_name);

    bool init();
    bool destroy();

    ~VulkanSystem();

    VulkanInstance* m_instance;
    Window* m_window;



    const uint32_t m_vulkanVersion = VK_API_VERSION_1_0;
};


#endif
