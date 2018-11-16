#ifndef VULKAN_COMMAND_POOL
#define VULKAN_COMMAND_POOL
#pragma once

#include "vulkan\vulkan.h"

#include "VulkanElement.h"

class VulkanCommandPool : public VulkanElement
{
public:
    VulkanCommandPool();

    bool init(SharedPtr<VulkanElement> vulkanSystem);
    bool destroy();

    bool trim();
    bool reset();

    ~VulkanCommandPool();

    VkCommandPool m_commandPool;
    VkDevice m_device;
};

#endif