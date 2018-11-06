#ifndef VULKAN_PHYSICAL_DEVICE
#define VULKAN_PHYSICAL_DEVICE
#pragma once

#include <string>

#include <vulkan\vulkan.h>

#include "VulkanElement.h"
#include "VulkanInstance.h"

class VulkanPhysicalDevice: public VulkanElement
{
public:
    VulkanPhysicalDevice();
    VulkanPhysicalDevice(const std::vector<const char*>& m_deviceExtensions);

    bool isDeviceSuitable(VkPhysicalDevice device);

    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    bool init(VulkanElement* instance = NULL);
    bool destroy();

    uint32_t getApiVersion();
    uint32_t getDriverVersion();
    uint32_t getVendorID();
    uint32_t getDeviceID();
    VkPhysicalDeviceType getDeviceType();
    std::string getDeviceName();

    ~VulkanPhysicalDevice();

    VkPhysicalDevice m_device;

protected:

    VkPhysicalDeviceProperties* getDeviceProperties();

    std::vector<const char*> m_deviceExtensions;

    VkPhysicalDeviceProperties* m_deviceProperties;
};

#endif