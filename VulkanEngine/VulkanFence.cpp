#include "VulkanFence.h"

#include "VulkanLogicalDevice.h"


VulkanFence::VulkanFence()
{
}

bool VulkanFence::init(VulkanElement* device)
{
    VkFenceCreateInfo createInfo;
    createInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    createInfo.pNext = NULL;
    createInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    if (vkCreateFence(((VulkanLogicalDevice*)device)->m_device, &createInfo, nullptr, &m_fence) != VK_SUCCESS)    {        m_init = false;        return false;    }    m_device = ((VulkanLogicalDevice*)device)->m_device;    m_init = true;    return true;
}

bool VulkanFence::initForExport(VulkanElement* device, VkExternalFenceHandleTypeFlags handleTypes)
{
    if (m_init)
    {
        return false;
    }

    VkExportFenceCreateInfo exportCreateInfo;
    exportCreateInfo.sType = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO;
    exportCreateInfo.pNext = NULL;
    exportCreateInfo.handleTypes = handleTypes;

    VkFenceCreateInfo createInfo;
    createInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    createInfo.pNext = &exportCreateInfo;
    createInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    if (vkCreateFence(((VulkanLogicalDevice*)device)->m_device, &createInfo, nullptr, &m_fence) != VK_SUCCESS)    {        m_init = false;        return false;    }    m_device = ((VulkanLogicalDevice*)device)->m_device;    m_handleTypeFlags = handleTypes;    m_init = true;    return true;
}

bool VulkanFence::destroy()
{

    vkDestroyFence(m_device, m_fence, NULL);

    return true;
}

int VulkanFence::getHandle()
{
    //TODO for windows this should be another version
    VkFenceGetFdInfoKHR getHandleInfo;
    getHandleInfo.sType = VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR;
    getHandleInfo.fence = m_fence;
    getHandleInfo.pNext = NULL;
    getHandleInfo.handleType = m_handleTypeFlags;


    int handle;

    if (vkGetFenceFdKHR(m_device, &getHandleInfo, &handle) != VK_SUCCESS)    {        return -1;    }    return handle;
}

VkResult VulkanFence::getStatus()
{
    return vkGetFenceStatus(m_device, m_fence);
}

bool VulkanFence::reset()
{
    if (vkResetFences(m_device, 1, &m_fence) != VK_SUCCESS)
    {
        return true;
    }

    return false;
}

bool VulkanFence::waitFence(long timeout = 10)
{
    vkWaitForFences(m_device, 1, &m_fence, true, timeout);
}

bool VulkanFence::waitFences(VulkanFence** fences, bool waitAll, long timeout)
{
    std::vector<VkFence> vulkanFences;
    
    unsigned int i = 0;
    while (fences[i] != NULL)
    {
        vulkanFences.push_back(fences[i]->m_fence);
    }

    vkWaitForFences(fences[0]->m_device, i, vulkanFences.data(), waitAll, timeout);

    return true;
}

bool VulkanFence::importPayLoad(int importFd, VkFenceImportFlags importFlags, VkExternalFenceHandleTypeFlagBits handleType)
{
    VkImportFenceFdInfoKHR importInfo;
    importInfo.sType = VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR;
    importInfo.pNext = NULL;
    importInfo.fence = m_fence;
    importInfo.flags = importFlags;
    importInfo.handleType = handleType;
    importInfo.fd = importFd;

    if (vkImportFenceFdKHR(m_device, &importInfo) != VK_SUCCESS)
    {
        return false;
    }

    return true;
}


VulkanFence::~VulkanFence()
{
    destroy();
}
