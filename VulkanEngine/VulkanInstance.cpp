#include "VulkanInstance.h"

#include "Log.h"


VulkanInstance::VulkanInstance()
{
    m_init = false;
}

VulkanInstance::VulkanInstance(SDL_Window* window, std::string application_name, uint32_t application_version, std::string engine_name, uint32_t engine_version, uint32_t vk_api_version)
{
    VkApplicationInfo applicationInfo = {};
    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pApplicationName = application_name.c_str();
    applicationInfo.applicationVersion = application_version;
    applicationInfo.pEngineName = engine_name.c_str();
    applicationInfo.engineVersion = engine_version;
    applicationInfo.apiVersion = vk_api_version;

    m_createInfo = {};
    m_createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    m_createInfo.pApplicationInfo = &applicationInfo;

    unsigned int extensionCount = getExtensionCount(window);
    const char** extentionNames;
    extentionNames = new const char *[extensionCount];
    getExtensionNames(window, extensionCount, extentionNames);

    m_createInfo.enabledExtensionCount = extensionCount;
    m_createInfo.ppEnabledExtensionNames = extentionNames;

    m_createInfo.enabledLayerCount = 0;
}

VulkanInstance::VulkanInstance(SDL_Window* window, std::string application_name, std::string engine_name, uint32_t vk_api_version) :VulkanInstance(window, application_name, 1, engine_name, 1, vk_api_version)
{
}

bool VulkanInstance::init()
{
    VkResult result = vkCreateInstance(&m_createInfo, nullptr, &m_instance);

    if (result != VK_SUCCESS)
    {
        m_init = false;

        //TODO добавить лог для вулкана с описанием ошибок
    }

    m_init = true;

    return m_init;
}

uint32_t VulkanInstance::getExtensionCount(SDL_Window* window)
{
    unsigned int extensionCount = 0;
    SDL_Vulkan_GetInstanceExtensions(window, &extensionCount, NULL);

    return extensionCount;
}

bool VulkanInstance::getExtensionNames(SDL_Window* window, uint32_t extenssion_count, const char** extension_names)
{
    return SDL_Vulkan_GetInstanceExtensions(window, &extenssion_count, extension_names);
}

bool VulkanInstance::destroy()
{
    if (m_init)
    {
        vkDestroyInstance(m_instance, NULL);
    }

    return true;
}

VulkanInstance::~VulkanInstance()
{
    destroy();
}
