#include "global.h"
#include "privileged.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Mode mode = USER_MODE; // Set initial mode to USER_MODE
CPU cpu = { .esp = memory + MAX_MEMORY - 1 }; // Initialize CPU state

void pushl(void* arg) {
  addl_esp(-8);
  memcpy(cpu.esp, arg, 8);
}

void movl_eax(int arg) {
  cpu.eax = arg;
}

int get_eax() {
  return cpu.eax;
}

void addl_esp(int arg) {
  cpu.esp += arg;
}

void* get_esp() {
  return cpu.esp;
}

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