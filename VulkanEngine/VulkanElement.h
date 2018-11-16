#ifndef VULKAN_ELEMENT
#define VULKAN_ELEMENT
#pragma once

#include <memory>

#define SharedPtr std::shared_ptr

class VulkanElement
{
public:
    VulkanElement();

    virtual bool init(SharedPtr<VulkanElement> vulkanElement);

    virtual bool destroy();

    bool isInit()
    {
        return m_init;
    }

    virtual ~VulkanElement();

    bool m_init;
};

#endif // !VULKAN_ELEMENT