#include "process_monitor.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

void ProcessMonitor::showProcesses()
{
    std::cout << "[ Processes ]\n";
    std::cout << "----------------------------\n";
    std::cout << "PID\tNAME\n";

    int count = 0;

    for (const auto& entry : fs::directory_iterator("/proc"))
    {
        if (!entry.is_directory())
            continue;

        std::string path = entry.path().filename().string();

        bool isNumber = true;

        for (char c : path)
        {
            if (!isdigit(c))
            {
                isNumber = false;
                break;
            }
        }

        if (isNumber)
        {
            std::ifstream file(
                "/proc/" + path + "/comm"
            );

            std::string name;

            if (file >> name)
            {
                std::cout
                    << path
                    << "\t"
                    << name
                    << "\n";

                count++;
            }
        }

        if (count >= 10)
            break;
    }

    std::cout << "\n";
}