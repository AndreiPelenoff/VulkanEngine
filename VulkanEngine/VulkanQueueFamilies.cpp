#include <vector>

#include "VulkanQueueFamilies.h"

#include "VulkanPhysicalDevice.h"

VulkanQueueFamilies::VulkanQueueFamilies()
{
}

bool VulkanQueueFamilies::init(VulkanElement* physical_device)
{
    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(((VulkanPhysicalDevice*)physical_device)->m_device, &queueFamilyCount, nullptr);

    m_queueFamilies.resize(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(((VulkanPhysicalDevice*)physical_device)->m_device, &queueFamilyCount, m_queueFamilies.data());

    m_init = true;

    return true;
}

int VulkanQueueFamilies::getFamilyQueueIndex(VkQueueFlagBits queFamily, VulkanPhysicalDevice* device, VulkanElement* surface)
{
    int i = 0;
    for (const auto& queueFamily : m_queueFamilies)
    {
        if (queueFamily.queueCount > 0 && queueFamily.queueFlags & queFamily)
        {
            if (surface != nullptr)
            {
                VkBool32 presentSupport = false;
                //vkGetPhysicalDeviceSurfaceSupportKHR(device->m_device, i, surface, &presentSupport);
            }

            return i;
        }

        i++;
    }

    return -1;
}

int VulkanQueueFamilies::getGraphicFamilyQueueIndex(VulkanPhysicalDevice* device, VulkanElement* surface)
{
    return getFamilyQueueIndex(VK_QUEUE_GRAPHICS_BIT, device, surface);
}

int VulkanQueueFamilies::getComputeFamilyQueueIndex(VulkanPhysicalDevice* device, VulkanElement* surface)
{
    return getFamilyQueueIndex(VK_QUEUE_COMPUTE_BIT, device, surface);
}

int VulkanQueueFamilies::getTransferFamilyQueueIndex(VulkanPhysicalDevice* device, VulkanElement* surface)
{
    return getFamilyQueueIndex(VK_QUEUE_TRANSFER_BIT, device, surface);
}

int VulkanQueueFamilies::getSparseBindingFamilyQueueIndex(VulkanPhysicalDevice* device, VulkanElement* surface)
{
    return getFamilyQueueIndex(VK_QUEUE_SPARSE_BINDING_BIT, device, surface);
}

bool VulkanQueueFamilies::destroy()
{
    if (m_init)
    {
        m_queueFamilies.clear();
        m_init = false;
    }

    return true;
}


VulkanQueueFamilies::~VulkanQueueFamilies()
{
}
