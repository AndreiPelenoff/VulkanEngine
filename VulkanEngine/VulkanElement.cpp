#include "VulkanElement.h"



VulkanElement::VulkanElement()
{
    m_init = false;
}

bool VulkanElement::init(SharedPtr<VulkanElement> vulkanElement)
{
    m_init = true;

    return true;
}

bool VulkanElement::destroy()
{
    m_init = false;

    return true;
}

VulkanElement::~VulkanElement()
{
    destroy();
}
