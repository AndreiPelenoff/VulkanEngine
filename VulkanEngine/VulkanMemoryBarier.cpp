#include "VulkanMemoryBarier.h"



VulkanMemoryBarier::VulkanMemoryBarier()
{
}

bool VulkanMemoryBarier::init(SharedPtr<VulkanElement> element = nullptr)
{
    return false;
}

bool VulkanMemoryBarier::init(VkAccessFlags sourceAccesMask, VkAccessFlags destinationAccessMask)
{
    m_memoryBarrier.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
    m_memoryBarrier.pNext = NULL;
    m_memoryBarrier.srcAccessMask = sourceAccesMask;
    m_memoryBarrier.dstAccessMask = destinationAccessMask;

    m_init = true;

    return true;
}

bool VulkanMemoryBarier::destroy()
{
    return true;
}


VulkanMemoryBarier::~VulkanMemoryBarier()
{
    destroy();
}
