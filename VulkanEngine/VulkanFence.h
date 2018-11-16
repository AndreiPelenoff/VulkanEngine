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

    bool init(SharedPtr<VulkanElement> device);
    bool initForExport(SharedPtr<VulkanElement>, VkExternalFenceHandleTypeFlags handleTypes);
    bool destroy();

    int getHandle(VkExternalFenceHandleTypeFlagBits handleType);
    VkResult getStatus();

    bool reset();

    bool waitFence(long timeout = 10);
    bool static waitFences(VulkanFence** fences, bool waitAll = true, long timeout = 10);

    bool importPayLoad(int importFd, VkFenceImportFlags importFlags, VkExternalFenceHandleTypeFlagBits handleType);

    ~VulkanFence();

    VkFence m_fence;
    VkDevice m_device;
    VkExternalFenceHandleTypeFlags m_handleTypeFlags;
};

#endif // !VULKAN_FENCE