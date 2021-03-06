#ifndef VULKAN_COMMAND_BUFFER
#define VULKAN_COMMAND_BUFFER
#pragma once

#include <vector>

#include "VulkanElement.h"
#include "VulkanCommandBuffer.h"

class VulkanCommandBuffer: public VulkanElement
{
public:
    VulkanCommandBuffer();

    bool init(SharedPtr<VulkanElement> vulkanSystem);
    bool destroy();

    bool reset(int buffer_number);
    bool free();

    //TODO separate to different functions by flags
    bool beginCommandBuffer(int buffer_number, VkCommandBufferUsageFlagBits flags);
    bool beginCommandBuffer(int buffer_number, VkCommandBufferUsageFlagBits flags, VkCommandBufferInheritanceInfo inheritanceInfo);

    bool endCommandBuffer(int buffer_number);

    ~VulkanCommandBuffer();

    std::vector<VkCommandBuffer> m_commandBuffers;
    SharedPtr<VulkanCommandPool> m_commandPool;
};

#endif // !VULKAN_COMMAND_BUFFER