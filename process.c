#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include "monitor.h"

void print_process_info() {
    struct dirent *entry;
    DIR *dp = opendir("/proc");

    if (!dp) {
        perror("opendir failed");
        return;
    }

    printf("[PROCESS] Running PIDs:\n");

    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            printf("PID: %s\n", entry->d_name);
        }
    }

    closedir(dp);
}