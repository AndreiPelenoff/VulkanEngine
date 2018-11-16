#include "VulkanSystem.h"

#include "VulkanSurface.h"



VulkanSurface::VulkanSurface()
{
    m_init = false;
}

bool VulkanSurface::init(SharedPtr<VulkanElement> vulkanSystem)
{
    if (vulkanSystem == nullptr)
    {
        return false;
    }

    if (std::dynamic_pointer_cast<VulkanSystem>(vulkanSystem)->m_window == nullptr)
    {
        return false;
    }

    if (!SDL_Vulkan_CreateSurface(std::dynamic_pointer_cast<VulkanSystem>(vulkanSystem)->m_window->window, std::dynamic_pointer_cast<VulkanSystem>(vulkanSystem)->m_instance->m_instance, &m_surface))
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
