#include <vector>
#include <string>
#include <set>

#include "VulkanPhysicalDevice.h"

#include "Log.h"


VulkanPhysicalDevice::VulkanPhysicalDevice()
{
    m_deviceProperties = NULL;
}

VulkanPhysicalDevice::VulkanPhysicalDevice(const std::vector<const char*>& deviceExtensions)
{
    m_deviceProperties = NULL;

    m_deviceExtensions = deviceExtensions;
}

bool VulkanPhysicalDevice::init(VulkanElement* instance)
{
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(((VulkanInstance*)(instance))->m_instance, &deviceCount, nullptr);

    if (deviceCount == 0)
    {
        m_init = false;

        Log::writeLog("no device available");
    }
    else
    {
        std::vector<VkPhysicalDevice> devices(deviceCount);
        vkEnumeratePhysicalDevices(((VulkanInstance*)(instance))->m_instance, &deviceCount, devices.data());

        for (const auto& device : devices) {
            if (isDeviceSuitable(device)) {
                m_device = device;
                break;
            }
        }

        if (m_device == VK_NULL_HANDLE) {
            Log::writeLog("failed to find a suitable GPU!");
            m_init = false;
        }

        m_init = true;;
    }

    return m_init;
}

bool VulkanPhysicalDevice::destroy()
{
    return true;
}

bool VulkanPhysicalDevice::checkDeviceExtensionSupport(VkPhysicalDevice device)
{
    uint32_t extensionCount;
    vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> availableExtensions(extensionCount);
    vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, availableExtensions.data());

    std::set<std::string> requiredExtensions(m_deviceExtensions.begin(), m_deviceExtensions.end());

    for (const auto& extension : availableExtensions) {
        requiredExtensions.erase(extension.extensionName);
    }

    return requiredExtensions.empty();
}

bool VulkanPhysicalDevice::isDeviceSuitable(VkPhysicalDevice device)
{
    bool extensionsSupported = checkDeviceExtensionSupport(device);

    VkPhysicalDeviceFeatures supportedFeatures;
    vkGetPhysicalDeviceFeatures(device, &supportedFeatures);

    return extensionsSupported && supportedFeatures.samplerAnisotropy;
}

uint32_t VulkanPhysicalDevice::getApiVersion()
{
    if (!m_init) return 0;

    if (m_deviceProperties == NULL)
    {
        if (getDeviceProperties() == NULL) return 0;
    }

    return m_deviceProperties->apiVersion;
}

uint32_t VulkanPhysicalDevice::getDriverVersion()
{
    if (!m_init) return 0;

    if (m_deviceProperties == NULL)
    {
        if (getDeviceProperties() == NULL) return 0;
    }

    return m_deviceProperties->driverVersion;
}

uint32_t VulkanPhysicalDevice::getVendorID()
{
    if (!m_init) return 0;

    if (m_deviceProperties == NULL)
    {
        if (getDeviceProperties() == NULL) return 0;
    }

    return m_deviceProperties->vendorID;
}

uint32_t VulkanPhysicalDevice::getDeviceID()
{
    if (!m_init) return 0;

    if (m_deviceProperties == NULL)
    {
        if (getDeviceProperties() == NULL) return 0;
    }

    return m_deviceProperties->deviceID;
}

VkPhysicalDeviceType VulkanPhysicalDevice::getDeviceType()
{
    if (!m_init) return VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_OTHER;

    if (m_deviceProperties == NULL)
    {
        if (getDeviceProperties() == NULL) return VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_OTHER;
    }

    return m_deviceProperties->deviceType;
}

std::string VulkanPhysicalDevice::getDeviceName()
{
    if (!m_init) return "";

    if (m_deviceProperties == NULL)
    {
        if (getDeviceProperties() == NULL) return "";
    }

    return m_deviceProperties->deviceName;
}

VkPhysicalDeviceProperties* VulkanPhysicalDevice::getDeviceProperties()
{
    if (m_init)
    {
        vkGetPhysicalDeviceProperties(m_device, m_deviceProperties);
    }

    return m_deviceProperties;
}


VulkanPhysicalDevice::~VulkanPhysicalDevice()
{
    destroy();
}
