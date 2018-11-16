#include "VulkanSystem.h"

VulkanSystem::VulkanSystem()
{
}

VulkanSystem::VulkanSystem(Window* window, std::string application_name) : m_window(window)
{
    m_instance = std::make_shared<VulkanInstance>(window->window, application_name, "vulkan", m_vulkanVersion);
    m_physicalDevice = NULL;
    m_surface = NULL;
    m_queueFamilies = NULL;
    m_logicalDevice = NULL;
    m_commandPool = NULL;
}

bool VulkanSystem::init(SharedPtr<VulkanElement> element)
{
    if (!m_instance->init())
    {
        m_init = false;
        return false;
    }

    m_physicalDevice = std::make_shared<VulkanPhysicalDevice>(m_deviceExtensions);

    if (!m_physicalDevice->init(m_instance))
    {
        m_init = false;
        return false;
    }

    m_surface = std::make_shared<VulkanSurface>();
    if (!m_surface->init(shared_from_this()))
    {
        m_init = false;

        return false;
    }

    m_queueFamilies = std::make_shared<VulkanQueueFamilies>();
    if (!m_queueFamilies->init(m_physicalDevice))
    {
        m_init = false;

        return false;
    }

    m_logicalDevice = std::make_shared<VulkanLogicalDevice>();
    if (!m_logicalDevice->init(shared_from_this()))
    {
        m_init = false;

        return false;
    }

    m_commandPool = std::make_shared<VulkanCommandPool>();
    if (!m_logicalDevice->init(shared_from_this()))
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
