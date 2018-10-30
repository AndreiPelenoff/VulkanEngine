#include "VulkanSystem.h"

VulkanSystem::VulkanSystem()
{
}

VulkanSystem::VulkanSystem(Window* window, std::string application_name) : m_window(window)
{
    m_instance = new VulkanInstance(window->window, application_name, "vulka", m_vulkanVersion);
}

bool VulkanSystem::init()
{
    if (!m_instance->init())
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
