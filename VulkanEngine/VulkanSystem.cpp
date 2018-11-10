#include "VulkanSystem.h"

VulkanSystem::VulkanSystem()
{
}

VulkanSystem::VulkanSystem(Window* window, std::string application_name) : m_window(window)
{
    m_instance = new VulkanInstance(window->window, application_name, "vulka", m_vulkanVersion);
    m_physicalDevice = NULL;
    m_surface = NULL;
    m_queueFamilies = NULL;
    m_logicalDevice = NULL;
}

bool VulkanSystem::init(VulkanElement* element)
{
    if (!m_instance->init())
    {
        m_init = false;
        return false;
    }

    m_physicalDevice = new VulkanPhysicalDevice(m_deviceExtensions);

    if (!m_physicalDevice->init(m_instance))
    {
        m_init = false;
        return false;
    }

    m_surface = new VulkanSurface();
    if (!m_surface->init(this))
    {
        m_init = false;

        return false;
    }

    m_queueFamilies = new VulkanQueueFamilies();
    if (!m_queueFamilies->init(m_physicalDevice))
    {
        m_init = false;

        return false;
    }

    m_logicalDevice = new VulkanLogicalDevice();
    if (!m_logicalDevice->init(this))
    {
        m_init = false;

        return false;
    }
        
    m_init = true;

    return true;
}

bool VulkanSystem::destroy()
{
    if (m_init)
    {
        m_instance->destroy();
    }

    return true;
}


VulkanSystem::~VulkanSystem()
{
    destroy();
}
