#ifndef VULKAN_SEMAPHORE
#define VULKAN_SEMAPHORE
#pragma once

#include <vulkan\vulkan.h>

#include "VulkanElement.h"

class VulkanSemaphore : public VulkanElement
{
public:
    VulkanSemaphore();

    bool init(VulkanElement* device);
    bool initForExport(VulkanElement* device, VkExternalSemaphoreHandleTypeFlagBits handleTypes);
    bool destroy();

    int getHandle();

    bool importPayLoad(int importFd, VkSemaphoreImportFlags importFlags, VkExternalSemaphoreHandleTypeFlagBits handleType);

    ~VulkanSemaphore();

    VkSemaphore m_semaphore;
    VkDevice m_device;
    VkExternalSemaphoreHandleTypeFlagBits m_handleTypes;
};

#endif // !VULKAN_SEMAPHORE