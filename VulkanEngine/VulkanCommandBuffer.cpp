#include "VulkanSystem.h"

#include "VulkanCommandBuffer.h"



VulkanCommandBuffer::VulkanCommandBuffer()
{
}

bool VulkanCommandBuffer::init(VulkanElement* vulkanSystem)
{
    //TODO should be count of swapchain Frame Buffer size
    m_commandBuffers.resize(1); 

    m_commandPool = ((VulkanSystem*)(vulkanSystem))->m_commandPool;

    VkCommandBufferAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.commandPool = m_commandPool->m_commandPool;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandBufferCount = (uint32_t)m_commandBuffers.size();

    if (vkAllocateCommandBuffers(m_commandPool->m_device, &allocInfo, m_commandBuffers.data()) != VK_SUCCESS) {
        
        m_init = false;

        return false;
    }

    return true;
}

bool VulkanCommandBuffer::destroy()
{
    return true;
}

bool VulkanCommandBuffer::reset(int buffer_number)
{
    if (vkResetCommandBuffer(m_commandBuffers[buffer_number], VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT) != VK_SUCCESS)
    {
        return false;
    }

    return true;
}

bool VulkanCommandBuffer::free()
{
    vkFreeCommandBuffers(m_commandPool->m_device, m_commandPool->m_commandPool, m_commandBuffers.size(), m_commandBuffers.data());

    return true;
}


bool VulkanCommandBuffer::beginCommandBuffer(int buffer_number, VkCommandBufferUsageFlagBits flags)
{
    VkCommandBufferBeginInfo beginInfo = {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = flags;
    beginInfo.pInheritanceInfo = nullptr; // Optional

    if (vkBeginCommandBuffer(m_commandBuffers[buffer_number], &beginInfo) != VK_SUCCESS) 
    {
        return false;
    }

    return true;
}

bool VulkanCommandBuffer::beginCommandBuffer(int buffer_number, VkCommandBufferUsageFlagBits flags, VkCommandBufferInheritanceInfo inheritanceInfo)
{
    //TODO should realise later with objects RenderPas, FrameBuffer and so on
    return false;
}

bool VulkanCommandBuffer::endCommandBuffer(int buffer_number)
{
    if (vkEndCommandBuffer(m_commandBuffers[buffer_number]) != VK_SUCCESS)
    {
        return false;
    }

    return true;
}


VulkanCommandBuffer::~VulkanCommandBuffer()
{
    destroy();
}
