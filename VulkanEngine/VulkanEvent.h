#ifndef VULKAN_EVENT
#define VULKAN_EVENT
#pragma once

#include <vulkan\vulkan.h>

#include "VulkanElement.h"
#include "VulkanLogicalDevice.h"

class VulkanEvent : public VulkanElement
{
public:
    VulkanEvent();

    bool init(SharedPtr<VulkanElement> logicalDevice = nullptr);
    bool destroy();

    VkResult getStatus();
    bool setEvent();
    bool resetEvent();

    bool setEventCmd(VkCommandBuffer commandBuffer, VkPipelineStageFlags stageMask);
    bool resetEventCmd(VkCommandBuffer commandBuffer, VkPipelineStageFlags stageMask);

    //TODO release function to wait events

    VkEvent m_event;
    SharedPtr<VulkanLogicalDevice> m_device;

    ~VulkanEvent();
};

#endif