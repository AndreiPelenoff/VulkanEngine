#include <iostream>
#include "Log.h"



Log::Log()
{
}

void Log::writeLog(std::string message)
{
    std::cout << message << std::endl;
}


Log::~Log()
{
}
