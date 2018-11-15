#include "VulkanLogicalDevice.h"

#include "VulkanSemaphore.h"



VulkanSemaphore::VulkanSemaphore()
{
}

bool VulkanSemaphore::init(VulkanElement* device)
{
    VkSemaphoreCreateInfo createInfo;
    createInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
    createInfo.pNext = NULL;
    createInfo.flags = 0;

    if (vkCreateSemaphore(((VulkanLogicalDevice*)device)->m_device, &createInfo, NULL, &m_semaphore) != VK_SUCCESS)
    {
        m_init = false;

        return false;
    }

    m_device = ((VulkanLogicalDevice*)device)->m_device;

    m_init = true;

    return true;
}

bool VulkanSemaphore::initForExport(VulkanElement* device, VkExternalSemaphoreHandleTypeFlagBits handleTypes)
{
    VkExportSemaphoreCreateInfo exportSemaphoreCreateInfo;
    exportSemaphoreCreateInfo.sType = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO;
    exportSemaphoreCreateInfo.pNext = NULL;
    exportSemaphoreCreateInfo.handleTypes = handleTypes;

    VkSemaphoreCreateInfo createInfo;
    createInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
    createInfo.pNext = &exportSemaphoreCreateInfo;
    createInfo.flags = 0;

    if (vkCreateSemaphore(((VulkanLogicalDevice*)device)->m_device, &createInfo, NULL, &m_semaphore) != VK_SUCCESS)
    {
        m_init = false;

        return false;
    }

    m_device = ((VulkanLogicalDevice*)device)->m_device;
    m_handleTypes = handleTypes;

    m_init = true;

    return true;
}

bool VulkanSemaphore::destroy()
{
    vkDestroySemaphore(m_device, m_semaphore, NULL);

    m_init = false;

    return true;
}

int VulkanSemaphore::getHandle()
{
    //TODO for windows this should be another version
    VkSemaphoreGetFdInfoKHR getHandleInfo;
    getHandleInfo.sType = VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR;
    getHandleInfo.semaphore = m_semaphore;
    getHandleInfo.pNext = NULL;
    getHandleInfo.handleType = m_handleTypes;


    int handle;

    if (vkGetSemaphoreFdKHR(m_device, &getHandleInfo, &handle) != VK_SUCCESS)    {        return -1;    }    return handle;
}


bool VulkanSemaphore::importPayLoad(int importFd, VkSemaphoreImportFlags importFlags, VkExternalSemaphoreHandleTypeFlagBits handleType)
{
    VkImportSemaphoreFdInfoKHR importInfo;
    importInfo.sType = VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR;
    importInfo.pNext = NULL;
    importInfo.semaphore = m_semaphore;
    importInfo.flags = importFlags;
    importInfo.handleType = handleType;
    importInfo.fd = importFd;

    if (vkImportSemaphoreFdKHR(m_device, &importInfo) != VK_SUCCESS)
    {
        return false;
    }

    return true;
}


VulkanSemaphore::~VulkanSemaphore()
{
    destroy();
}
