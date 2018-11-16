#include "VulkanEvent.h"



VulkanEvent::VulkanEvent()
{
}

bool VulkanEvent::init(SharedPtr<VulkanElement> logicalDevice)
{
    m_device = std::dynamic_pointer_cast<VulkanLogicalDevice>(logicalDevice);
    
    VkEventCreateInfo createInfo;
    createInfo.sType = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
    createInfo.pNext = NULL;
    createInfo.flags = 0;

    if (vkCreateEvent(m_device->m_device, &createInfo, NULL, &m_event) != VK_SUCCESS)
    {
        m_init = false;

        return false;
    }

    m_init = true;

    return true;
}

bool VulkanEvent::destroy()
{
    vkDestroyEvent(m_device->m_device, m_event, NULL);

    m_init = false;

    return true;
}

VkResult VulkanEvent::getStatus()
{
    return vkGetEventStatus(m_device->m_device, m_event);
}

bool VulkanEvent::setEvent()
{
    if (vkSetEvent(m_device->m_device, m_event) != VK_SUCCESS)
    {
        return false;
    }

    return true;
}

bool VulkanEvent::resetEvent()
{
    if (vkResetEvent(m_device->m_device, m_event) != VK_SUCCESS)
    {
        return false;
    }

    return true;
}

bool VulkanEvent::setEventCmd(VkCommandBuffer commadBuffer, VkPipelineStageFlags stageMask)
{
    vkCmdSetEvent(commadBuffer, m_event, stageMask);

    return true;
}

bool VulkanEvent::resetEventCmd(VkCommandBuffer commadBuffer, VkPipelineStageFlags stageMask)
{
    vkCmdResetEvent(commadBuffer, m_event, stageMask);

    return true;
}


VulkanEvent::~VulkanEvent()
{
    destroy();
}
