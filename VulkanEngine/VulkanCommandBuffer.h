#ifndef VULKAN_COMMAND_BUFFER
#define VULKAN_COMMAND_BUFFER
#pragma once

#include <vector>

#include "VulkanElement.h"

class VulkanCommandBuffer: public VulkanElement
{
public:
    VulkanCommandBuffer();

    bool init(VulkanElement* vulkanSystem);
    bool destroy();

    bool reset(int buffer_number);
    bool free();

    ~VulkanCommandBuffer();

    std::vector<VkCommandBuffer> m_commandBuffers;
    VulkanCommandPool* m_commandPool;
};

#endif // !VULKAN_COMMAND_BUFFER