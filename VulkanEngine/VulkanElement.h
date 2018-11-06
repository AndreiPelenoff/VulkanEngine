#ifndef VULKAN_ELEMENT
#define VULKAN_ELEMENT
#pragma once

class VulkanElement
{
public:
    VulkanElement();

    virtual bool init(VulkanElement* vulkanElement = nullptr) = 0;

    virtual bool destroy() = 0;

    bool isInit()
    {
        return m_init;
    }

    ~VulkanElement();

    bool m_init;
};

#endif // !VULKAN_ELEMENT