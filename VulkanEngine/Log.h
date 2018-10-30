#ifndef LOG
#define LOG
#pragma once

#include <string>

class Log
{
public:
    Log();

    static void writeLog(std::string message);

    ~Log();
};

#endif // !LOG