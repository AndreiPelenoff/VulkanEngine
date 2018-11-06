#ifndef VULKAN_QUEUE_FAMILIES
#define VULKAN_QUEUE_FAMILIES
#pragma once

#include <optional>

#include <vulkan\vulkan.h>

#include "VulkanElement.h"
#include "VulkanPhysicalDevice.h"

class VulkanQueueFamilies: public VulkanElement
{
public:
    VulkanQueueFamilies();

    bool init(VulkanElement* physical_device);
    bool destroy();

    int getGraphicFamilyQueueIndex(VulkanPhysicalDevice* device = nullptr, VulkanElement* surface = nullptr);
    int getComputeFamilyQueueIndex(VulkanPhysicalDevice* device = nullptr, VulkanElement* surface = nullptr);
    int getTransferFamilyQueueIndex(VulkanPhysicalDevice* device = nullptr, VulkanElement* surface = nullptr);
    int getSparseBindingFamilyQueueIndex(VulkanPhysicalDevice* device = nullptr, VulkanElement* surface = nullptr);

    int getFamilyQueueIndex(VkQueueFlagBits queFamily, VulkanPhysicalDevice* device = nullptr, VulkanElement* surface = nullptr);

    std::vector<VkQueueFamilyProperties> m_queueFamilies;

    ~VulkanQueueFamilies();

    
};

#endif