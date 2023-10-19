#ifndef GLOBAL_H
#define GLOBAL_H

#define MAX_MEMORY 1024 // Define maximum memory size

// System call number table
#define SYS_AA 0

// Enum for CPU modes
typedef enum { USER_MODE, KERNEL_MODE } Mode;

// Structure for CPU state
typedef struct {
    unsigned int eax;
    unsigned int esp;
} CPU;

char memory[MAX_MEMORY]; 

Mode get_cpu_mode(void);

extern CPU cpu;

#endif