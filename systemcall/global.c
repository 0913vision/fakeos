#include "global.h"
#include "privileged.h"

Mode mode = USER_MODE; // Set initial mode to USER_MODE
CPU cpu = { .esp = MAX_MEMORY-1, .mode = USER_MODE }; // Initialize CPU state

// Function to retrieve the current CPU mode
Mode get_cpu_mode(void) {
  return mode;
}

// Function to switch CPU mode to KERNEL_MODE
void switch_to_kernel_mode(void) {
  mode = KERNEL_MODE;
}

// Function to switch CPU mode to USER_MODE
void switch_to_user_mode(void) {
  mode = USER_MODE;
}