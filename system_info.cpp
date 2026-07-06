#include "system_info.h"
#include <unistd.h>


std::string SystemInfo::getHostname()
{
    char name[256];

    if(gethostname(name, sizeof(name)) == 0)
        return std::string(name);

    return "Unknown";
}