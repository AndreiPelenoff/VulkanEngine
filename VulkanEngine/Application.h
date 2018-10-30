#ifndef APPLICATION
#define APPLICATION
#pragma once

class Application
{
public:
    Application();

    virtual bool run() = 0;

    virtual bool mainLoop() = 0;

    virtual ~Application();
};

#endif