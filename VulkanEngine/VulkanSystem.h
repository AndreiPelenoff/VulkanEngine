#ifndef VULKAN_SYSTEM
#define VULKAN_SYSTEM
#pragma once

#include <vector>

#include "Window.h"

#include "VulkanElement.h"

#include "VulkanInstance.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanSurface.h"
#include "VulkanQueueFamilies.h"
#include "VulkanLogicalDevice.h"
#include "VulkanCommandPool.h"

class VulkanSystem : public VulkanElement
{
public:
    VulkanSystem();

    VulkanSystem(Window* window, std::string application_name);

    bool init(VulkanElement* element = nullptr);
    bool destroy();

    ~VulkanSystem();

    VulkanInstance* m_instance;
    VulkanPhysicalDevice* m_physicalDevice;
    VulkanSurface* m_surface;
    VulkanQueueFamilies* m_queueFamilies;
    VulkanLogicalDevice* m_logicalDevice;
    VulkanCommandPool* m_commandPool;

    Window* m_window;



    const uint32_t m_vulkanVersion = VK_API_VERSION_1_0;
    const std::vector<const char*> m_deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
};


#endif
