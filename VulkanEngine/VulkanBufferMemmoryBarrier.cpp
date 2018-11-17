#include "VulkanBufferMemmoryBarrier.h"



VulkanBufferMemmoryBarrier::VulkanBufferMemmoryBarrier()
{
}


bool VulkanBufferMemmoryBarrier::init(SharedPtr<VulkanElement> element)
{
    return false;
}

bool VulkanBufferMemmoryBarrier::init(VkAccessFlags sourceAccesMask, VkAccessFlags destinationAccessMask, uint32_t srcQueueFamilyIndex, uint32_t dstQueueFamilyIndex, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size)
{
    m_bufferMemmoryBarrier.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
    m_bufferMemmoryBarrier.pNext = NULL;
    m_bufferMemmoryBarrier.srcAccessMask = sourceAccesMask;
    m_bufferMemmoryBarrier.dstAccessMask = destinationAccessMask;
    m_bufferMemmoryBarrier.srcQueueFamilyIndex = srcQueueFamilyIndex;
    m_bufferMemmoryBarrier.dstQueueFamilyIndex = dstQueueFamilyIndex;
    m_bufferMemmoryBarrier.buffer = buffer;
    m_bufferMemmoryBarrier.offset = offset;
    m_bufferMemmoryBarrier.size = size;

    m_init = true;

    return true;
}

bool VulkanBufferMemmoryBarrier::destroy()
{
    return true;
}


VulkanBufferMemmoryBarrier::~VulkanBufferMemmoryBarrier()
{
    destroy();
}
