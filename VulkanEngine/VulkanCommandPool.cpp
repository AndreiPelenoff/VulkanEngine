#include "VulkanSystem.h"

#include "VulkanCommandPool.h"



VulkanCommandPool::VulkanCommandPool()
{
}

bool VulkanCommandPool::init(VulkanElement* vulkanSystem)
{
    VkCommandPoolCreateInfo poolInfo = {};
    poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    poolInfo.queueFamilyIndex = ((VulkanSystem*)(vulkanSystem))->m_queueFamilies->getGraphicFamilyQueueIndex();
    poolInfo.flags = 0; // Optional

    m_device = ((VulkanSystem*)(vulkanSystem))->m_logicalDevice->m_device;

    if (vkCreateCommandPool(m_device, &poolInfo, nullptr, &m_commandPool) != VK_SUCCESS) {

        m_init = false;

        return false;
    }

    m_init = true;

    return true;
}


bool VulkanCommandPool::destroy()
{
    if (m_init)
    {
        m_init = false;

        vkDestroyCommandPool(m_device, m_commandPool, nullptr);
    }

    return true;
}

bool VulkanCommandPool::reset()
{
    if (vkResetCommandPool(m_device, m_commandPool, VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT) != VK_SUCCESS)
    {
        return false;
    }

    return true;
}

bool VulkanCommandPool::trim()
{
    //vkTrimCommandPoolKHR(m_device, m_commandPool, 0);

    return true;
}


VulkanCommandPool::~VulkanCommandPool()
{
    destroy();
}
