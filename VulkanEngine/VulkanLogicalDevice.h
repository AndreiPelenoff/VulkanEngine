#ifndef VULKAN_LOGICAL_DEVICE
#define VULKAN_LOGICAL_DEVICE
#pragma once

#include <vulkan\vulkan.hpp>

#include "VulkanElement.h"

class VulkanLogicalDevice: public VulkanElement
{
public:
    VulkanLogicalDevice();

    bool init(VulkanElement* physicalDevice);
    bool destroy();

    ~VulkanLogicalDevice();
};

#endif