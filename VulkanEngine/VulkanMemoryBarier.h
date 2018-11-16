#ifndef VULKAN_MEMORY_BARRIER
#define VULKAN_MEMORY_BARRIER
#pragma once

#include <vulkan\vulkan.h>

#include "VulkanElement.h"

class VulkanMemoryBarier : public VulkanElement
{
public:
    VulkanMemoryBarier();

    bool init(SharedPtr<VulkanElement> element = nullptr);
    bool init(VkAccessFlags sourceAccesMask, VkAccessFlags destinationAccessMask);

    bool destroy();

    ~VulkanMemoryBarier();

    VkMemoryBarrier m_memoryBarrier;
};

#endif