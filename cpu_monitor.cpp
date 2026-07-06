#include "cpu_monitor.h"
#include <fstream>
#include <string>
#include <unistd.h>


double CPUMonitor::getUsage()
{
    std::ifstream file("/proc/stat");

    if(!file)
        return 0;

    std::string cpu;
    long user, nice, system, idle;

    file >> cpu >> user >> nice >> system >> idle;

    long total = user + nice + system + idle;

    if(total == 0)
        return 0;

    double usage =
        100.0 * (total - idle) / total;

    return usage;
}