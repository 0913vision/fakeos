#include "global.h"
#include "kernel.h"

#include <stdio.h>
#include <stdlib.h>

// Function to simulate a kernel panic
void kernel_panic() {
    printf("*** kernel panic ***\n");
    exit(-1);
}

void kernel_function(char *msg) {
    if(get_cpu_mode() != KERNEL_MODE) {
        kernel_panic();
    }
    printf("Kernel received message: %s\n", msg);
}
