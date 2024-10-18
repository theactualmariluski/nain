/*
##############################
## Nain VM Making          ##
##############################
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>
#include <stdbool.h>
#include "../libs/log.h"

#ifndef vm_make_h
#define vm_make_h

#define VM_MAKE_VERSION "0.1.0"

struct VM_CONFIGURATION {
    int maxRAM;       // the maximum RAM size in megabytes
    int maxDisk;      // the maximum disk size in megabytes
    int maxInstances; // the maximum number of VMs that can be running
    bool fillDisk;    // whether to fill the disk with zeros
};

// Removed this macro as it does not point to an instance
// #define VM_CONFIG VM_CONFIGURATION

int getRAM(struct VM_CONFIGURATION config);
int getDisk(struct VM_CONFIGURATION config, bool fillFile);

int vm_make(struct VM_CONFIGURATION config) {
    // Check the configuration before allocating resources
    if (config.maxRAM <= 0 || config.maxDisk <= 0 || config.maxInstances <= 0) {
        printf("fatal vm error: \n \
        |---------------------| \n \
        | vm config is on zero|\n\
        |---------------------| \n\n \
        |--hint------------------------------------------|  \n \
        | make sure RAM, DISK and instances are not zero |\n \
        |------------------------------------------------| \n");
        return 1;
    }

    // Gets some RAM
    getRAM(config);
    
    // Gets disk space
    if (config.fillDisk) {
        getDisk(config, true);
    } else {
        getDisk(config, false);
    }
    return 0; // Indicate success
}

int getRAM(struct VM_CONFIGURATION config) {
    void* ram = malloc(config.maxRAM * 1024 * 1024);
    if (ram == NULL) {
        printf("fatal vm error: could not allocate RAM.\n");
        return 1;
    }
    // You might want to handle the allocated RAM here (e.g., initialize it)
    return 0; // Indicate success
}

int getDisk(struct VM_CONFIGURATION config, bool fillFile) {
    // Create a new file (to get space)
    int fd = open("disk.iso", O_RDWR | O_CREAT | O_TRUNC, 0666); // Creates a new file with the specified name and permissions
    if (fd == -1) { // Checks for errors
        printf("fatal vm error: could not create disk, check permissions. \n");
        return 1;
    } else { // If not...
        printf("vm info: disk.iso created. \n");
    }

    if (fillFile) {
        // Fill the file with zeros (if asked)
        char zeroBuffer[4096] = {0}; // Buffer to write in chunks
        size_t totalSize = config.maxDisk * 1024 * 1024;
        for (size_t i = 0; i < totalSize; i += sizeof(zeroBuffer)) {
            size_t bytesToWrite = (i + sizeof(zeroBuffer) > totalSize) ? 
                                  (totalSize - i) : sizeof(zeroBuffer);
            write(fd, zeroBuffer, bytesToWrite);
        }
    }

    // Close the file descriptor
    close(fd);
    return 0; // Indicate success
}

#endif
