#ifndef VULKAN_BUFFER_MEMMORY_BARRIER
#define VULKAN_BUFFER_MEMMORY_BARRIER
#pragma once

#include "VulkanElement.h"

#include <vulkan\vulkan.h>

class VulkanBufferMemmoryBarrier : public VulkanElement
{
public:
    VulkanBufferMemmoryBarrier();

    bool init(SharedPtr<VulkanElement> element = nullptr);
    bool init(VkAccessFlags sourceAccesMask, VkAccessFlags destinationAccessMask, uint32_t srcQueueFamilyIndex, uint32_t dstQueueFamilyIndex, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size);

    bool destroy();

    ~VulkanBufferMemmoryBarrier();

    VkBufferMemoryBarrier m_bufferMemmoryBarrier;
};

#endif