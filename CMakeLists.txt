cmake_minimum_required(VERSION 3.10)

project(LinuxSystemMonitor)

set(CMAKE_CXX_STANDARD 17)

add_executable(
    linux-system-monitor
    main.cpp
    cpu_monitor.cpp
    memory_monitor.cpp
    system_info.cpp
    process_monitor.cpp
)