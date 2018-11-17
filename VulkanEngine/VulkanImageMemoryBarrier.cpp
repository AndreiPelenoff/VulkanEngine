#include "VulkanImageMemoryBarrier.h"



VulkanImageMemoryBarrier::VulkanImageMemoryBarrier()
{
}

bool VulkanImageMemoryBarrier::init(SharedPtr<VulkanElement> element)
{
    m_init = false;

    return true;
}

bool VulkanImageMemoryBarrier::init(VkAccessFlags sourceAccesMask, VkAccessFlags destinationAccessMask, uint32_t srcQueueFamilyIndex, uint32_t dstQueueFamilyIndex, VkImage image, VkImageSubresourceRange subResourceRanfe)
{
    m_imageMemoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    m_imageMemoryBarrier.pNext = NULL;
    m_imageMemoryBarrier.srcAccessMask = sourceAccesMask;
    m_imageMemoryBarrier.dstAccessMask = destinationAccessMask;
    m_imageMemoryBarrier.srcQueueFamilyIndex = srcQueueFamilyIndex;
    m_imageMemoryBarrier.dstQueueFamilyIndex = dstQueueFamilyIndex;
    m_imageMemoryBarrier.image = image;
    m_imageMemoryBarrier.subresourceRange = subResourceRanfe;

    m_init = true;

    return true;
}

bool VulkanImageMemoryBarrier::destroy()
{
    m_init = false;

    return true;
}


VulkanImageMemoryBarrier::~VulkanImageMemoryBarrier()
{
    destroy();
}
