#include <iostream>

#include "VulkanApplication.h"

#undef main

int main(int argc, char* argv[])
{
    VulkanApplication app1("vulkan", 800, 600);

    int a;
    std::cin >> a;

    return 0;
}