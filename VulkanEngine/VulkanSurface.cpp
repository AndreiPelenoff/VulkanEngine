#include "VulkanSystem.h"

#include "VulkanSurface.h"



VulkanSurface::VulkanSurface()
{
    m_init = false;
}

bool VulkanSurface::init(VulkanElement* vulkanSystem)
{
    if (vulkanSystem == nullptr)
    {
        return false;
    }

    if (((VulkanSystem*)vulkanSystem)->m_window == nullptr)
    {
        return false;
    }

    if (!SDL_Vulkan_CreateSurface(((VulkanSystem*)vulkanSystem)->m_window->window, ((VulkanSystem*)vulkanSystem)->m_instance->m_instance, &m_surface))
    {
        m_init = false;
        return false;
    }

    return true;
}

bool VulkanSurface::destroy()
{
    if (m_init)
    {
        m_init = false;
    }

    return true;
}


VulkanSurface::~VulkanSurface()
{
    destroy();
}
