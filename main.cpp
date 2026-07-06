#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "cpu_monitor.h"
#include "memory_monitor.h"
#include "system_info.h"

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    SystemInfo system;
    CPUMonitor cpu;
    MemoryMonitor memory;

    while (true)
    {
        clearScreen();

        std::cout << "====================================\n";
        std::cout << "       Linux System Monitor\n";
        std::cout << "====================================\n\n";

        std::cout << "Hostname : "
                  << system.getHostname()
                  << "\n\n";

        std::cout << "[ CPU ]\n";
        std::cout << "Usage    : "
                  << cpu.getUsage()
                  << " %\n\n";

        std::cout << "[ Memory ]\n";
        std::cout << "Used     : "
                  << memory.getUsedMemory()
                  << " MB\n";

        std::cout << "Total    : "
                  << memory.getTotalMemory()
                  << " MB\n\n";

        std::cout << "Refreshing every 1 second...\n";

        std::this_thread::sleep_for(
            std::chrono::seconds(1)
        );
    }

    return 0;
}