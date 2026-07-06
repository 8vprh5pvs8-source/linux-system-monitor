#include "disk_monitor.h"

#include <iostream>
#include <sys/statvfs.h>

void DiskMonitor::showDiskUsage()
{
    struct statvfs disk;

    if (statvfs("/", &disk) != 0)
    {
        std::cout << "Disk information unavailable\n";
        return;
    }

    unsigned long total =
        disk.f_blocks * disk.f_frsize;

    unsigned long available =
        disk.f_bavail * disk.f_frsize;

    unsigned long used =
        total - available;


    double usedGB =
        used / (1024.0 * 1024.0 * 1024.0);

    double totalGB =
        total / (1024.0 * 1024.0 * 1024.0);


    std::cout << "[ Disk ]\n";
    std::cout << "Used  : "
              << usedGB
              << " GB\n";

    std::cout << "Total : "
              << totalGB
              << " GB\n\n";
}