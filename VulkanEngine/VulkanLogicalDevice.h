#ifndef VULKAN_LOGICAL_DEVICE
#define VULKAN_LOGICAL_DEVICE
#pragma once

#include <vulkan\vulkan.hpp>

#include "VulkanElement.h"

class VulkanLogicalDevice: public VulkanElement
{
public:
    VulkanLogicalDevice();

    bool init(VulkanElement* system);
    bool destroy();

    ~VulkanLogicalDevice();

    VkDevice m_device;
    VkQueue m_graphicsQueue;
    VkQueue m_presentQueue;
};

#endif