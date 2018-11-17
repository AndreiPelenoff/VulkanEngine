#ifndef VULKAN_IMAGE_MEMMORY_BARRIER
#define VULKAN_IMAGE_MEMMORY_BARRIER
#pragma once

#include <vulkan\vulkan.h>

#include "VulkanElement.h"


class VulkanImageMemoryBarrier : public VulkanElement
{
public:
    VulkanImageMemoryBarrier();

    bool init(SharedPtr<VulkanElement> element = nullptr);
    bool init(VkAccessFlags sourceAccesMask, VkAccessFlags destinationAccessMask, uint32_t srcQueueFamilyIndex, uint32_t dstQueueFamilyIndex, VkImage image, VkImageSubresourceRange subResourceRanfe);

    bool destroy();

    ~VulkanImageMemoryBarrier();

    VkImageMemoryBarrier m_imageMemoryBarrier;
};

#endif