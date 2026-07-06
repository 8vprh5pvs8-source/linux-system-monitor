#include <stdio.h>
#include "monitor.h"

void print_memory_usage() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    char label[20];
    long total, free;

    fscanf(fp, "%s %ld kB", label, &total);
    fscanf(fp, "%s %ld kB", label, &free);

    fclose(fp);

    long used = total - free;

    printf("[MEM] Used: %ld kB / Total: %ld kB\n", used, total);
}