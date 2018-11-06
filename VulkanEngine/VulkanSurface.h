#ifndef VULKAN_SURFACE
#define VULKAN_SURFACE
#pragma once

#include <vulkan\vulkan.h>

#include "VulkanElement.h"

class VulkanSurface: public VulkanElement
{
public:
    VulkanSurface();

    bool init(VulkanElement* vulkanSystem = nullptr);

    bool destroy();

    ~VulkanSurface();

    VkSurfaceKHR m_surface; 
};

#endif