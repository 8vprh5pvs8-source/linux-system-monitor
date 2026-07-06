#include <iostream>
#include "cpu_monitor.h"
#include "memory_monitor.h"
#include "system_info.h"

int main()
{
    std::cout << "=============================\n";
    std::cout << " Linux System Monitor (C++)\n";
    std::cout << "=============================\n\n";

    SystemInfo system;

    std::cout << "Hostname: "
              << system.getHostname()
              << "\n\n";

    CPUMonitor cpu;
    MemoryMonitor memory;

    std::cout << "[CPU]\n";
    std::cout << "Usage: "
              << cpu.getUsage()
              << "%\n\n";

    std::cout << "[Memory]\n";
    std::cout << "Used: "
              << memory.getUsedMemory()
              << " MB\n";

    std::cout << "Total: "
              << memory.getTotalMemory()
              << " MB\n";

    return 0;
}