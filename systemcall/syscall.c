#include "syscall.h"
#include "intr.h"
#include "global.h"

int syscall1(int syscall_no, char *arg0) {
    int arg_len = strlen(arg0) + 1;
    cpu.esp -= arg_len;
    strcpy(memory + cpu.esp, arg0);

    cpu.esp -= sizeof(int);
    *((int *)(memory + cpu.esp)) = syscall_no;

    interrupt_handler();

    return cpu.eax;
}

// TODO 2: 새로운 syscallN 만들기