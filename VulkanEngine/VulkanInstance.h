#ifndef VULKAN_INSTANCE
#define VULKAN_INSTANCE
#pragma once

#include <string>

#include <SDL_vulkan.h>

#include <vulkan\vulkan.h>

#include "VulkanElement.h"

class VulkanInstance : VulkanElement
{
public:
    VulkanInstance();
    VulkanInstance(SDL_Window* window, std::string application_name, uint32_t application_version, std::string engine_name, uint32_t engine_version, uint32_t vk_api_version);
    VulkanInstance(SDL_Window* window, std::string application_name, std::string engine_name, uint32_t vk_api_version);

    bool init();
    bool destroy();

    uint32_t getExtensionCount(SDL_Window* window);
    bool getExtensionNames(SDL_Window* window, uint32_t extenssion_count, const char** extension_names);

    ~VulkanInstance();

    VkInstance m_instance;
    VkInstanceCreateInfo m_createInfo;
};

#endif