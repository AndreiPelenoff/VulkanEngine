#ifndef VULKAN_FENCE
#define VULKAN_FENCE
#pragma once

#include <vulkan\vulkan.h>

#include "VulkanElement.h"

typedef void * HANDLE;

class VulkanFence : public VulkanElement
{
public:
    VulkanFence();

    bool init(VulkanElement* device);
    bool initForExport(VulkanElement* device, VkExternalFenceHandleTypeFlags handleTypes);
    bool destroy();

    int getHandle();
    VkResult getStatus();

    bool reset();

    bool static waitFences(VulkanFence** fences, bool waitAll = true, long timeout = 10);

    bool importPayLoad(int importFd, VkFenceImportFlags importFlags, VkExternalFenceHandleTypeFlagBits handleType);

    ~VulkanFence();

    VkFence m_fence;
    VkDevice m_device;
    VkExternalFenceHandleTypeFlags m_handleTypeFlags;
};

#endif // !VULKAN_FENCE