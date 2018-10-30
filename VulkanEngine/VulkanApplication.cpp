#include "VulkanApplication.h"



VulkanApplication::VulkanApplication(std::string application_name, uint32_t width, uint32_t height)
{
    m_window = new Window(width, height, application_name);

    m_vulkanSystem = new VulkanSystem(m_window, application_name);
}

bool VulkanApplication::run()
{
    mainLoop();

    return true;
}

bool VulkanApplication::mainLoop()
{
    while (true)
    {
        
    }

    return true;
}


VulkanApplication::~VulkanApplication()
{
}
