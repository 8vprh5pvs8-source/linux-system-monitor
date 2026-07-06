#include <stdio.h>
#include "monitor.h"

int main() {
    printf("=== Linux System Monitor ===\n\n");

    print_cpu_usage();
    print_memory_usage();
    print_process_info();

    return 0;
}