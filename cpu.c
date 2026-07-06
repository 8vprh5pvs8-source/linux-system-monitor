#include <stdio.h>
#include <stdlib.h>
#include "monitor.h"

void print_cpu_usage() {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        return;
    }

    char cpu[5];
    long user, nice, system, idle;

    fscanf(fp, "%s %ld %ld %ld %ld", cpu, &user, &nice, &system, &idle);
    fclose(fp);

    long total = user + nice + system + idle;
    long active = user + nice + system;

    printf("[CPU] Active: %ld | Total: %ld\n", active, total);
}