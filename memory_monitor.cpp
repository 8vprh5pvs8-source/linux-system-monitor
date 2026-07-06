#include "memory_monitor.h"
#include <fstream>
#include <string>


long MemoryMonitor::getTotalMemory()
{
    std::ifstream file("/proc/meminfo");

    std::string key;
    long value;

    while(file >> key >> value)
    {
        if(key == "MemTotal:")
            return value / 1024;
    }

    return 0;
}


long MemoryMonitor::getUsedMemory()
{
    std::ifstream file("/proc/meminfo");

    std::string key;
    long total = 0;
    long available = 0;
    long value;

    while(file >> key >> value)
    {
        if(key == "MemTotal:")
            total = value;

        if(key == "MemAvailable:")
            available = value;
    }

    return (total - available) / 1024;
}