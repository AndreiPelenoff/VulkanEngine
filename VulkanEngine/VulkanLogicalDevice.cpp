#include <set>

#include "VulkanPhysicalDevice.h"
#include "VulkanSystem.h"

#include "VulkanLogicalDevice.h"



VulkanLogicalDevice::VulkanLogicalDevice()
{
}

bool VulkanLogicalDevice::init(SharedPtr<VulkanElement> system)
{
    //QueueFamilyIndices indices = findQueueFamilies(physicalDevice);

    VkDeviceQueueCreateInfo queueCreateInfo = {};
    queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queueCreateInfo.queueFamilyIndex = (std::dynamic_pointer_cast<VulkanSystem>(system)->m_queueFamilies->getGraphicFamilyQueueIndex());
    queueCreateInfo.queueCount = 1;

    std::set<uint32_t> uniqueQueueFamilies = { static_cast<uint32_t>(std::dynamic_pointer_cast<VulkanSystem>(system)->m_queueFamilies->getGraphicFamilyQueueIndex()),   static_cast<uint32_t>(std::dynamic_pointer_cast<VulkanSystem>(system)->m_queueFamilies->getTransferFamilyQueueIndex())};

    float queuePriority = 1.0f;
    queueCreateInfo.pQueuePriorities = &queuePriority;

    //Fill it later
    VkPhysicalDeviceFeatures deviceFeatures = {};
    deviceFeatures.samplerAnisotropy = VK_TRUE;

    VkDeviceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

    createInfo.pQueueCreateInfos = &queueCreateInfo;
    createInfo.queueCreateInfoCount = 1;

    createInfo.pEnabledFeatures = &deviceFeatures;

    createInfo.enabledLayerCount = 0;

    createInfo.enabledExtensionCount = static_cast<uint32_t>(std::dynamic_pointer_cast<VulkanSystem>(system)->m_deviceExtensions.size());
    createInfo.ppEnabledExtensionNames = (std::dynamic_pointer_cast<VulkanSystem>(system))->m_deviceExtensions.data();

    if (vkCreateDevice(std::dynamic_pointer_cast<VulkanSystem>(system)->m_physicalDevice->m_device, &createInfo, nullptr, &m_device) != VK_SUCCESS) {
        m_init = false;

        return false;
    }

    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;

    for (uint32_t queueFamily : uniqueQueueFamilies) {
        VkDeviceQueueCreateInfo queueCreateInfo = {};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = queueFamily;
        queueCreateInfo.queueCount = 1;
        queueCreateInfo.pQueuePriorities = &queuePriority;
        queueCreateInfos.push_back(queueCreateInfo);
    }

    createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
    createInfo.pQueueCreateInfos = queueCreateInfos.data();

    vkGetDeviceQueue(m_device, std::dynamic_pointer_cast<VulkanSystem>(system)->m_queueFamilies->getGraphicFamilyQueueIndex(), 0, &m_graphicsQueue);
    vkGetDeviceQueue(m_device, std::dynamic_pointer_cast<VulkanSystem>(system)->m_queueFamilies->getTransferFamilyQueueIndex(), 0, &m_presentQueue);

    m_init = true;

    return true;
}

bool VulkanLogicalDevice::destroy()
{
    if (m_init)
    {
        m_init = false;

        vkDestroyDevice(m_device, NULL);
    }

    return true;
}


VulkanLogicalDevice::~VulkanLogicalDevice()
{
    destroy();
}
