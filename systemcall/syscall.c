#include "syscall.h"
#include "intr.h"
#include "global.h"
#include <stdio.h>

int syscall1(int syscall_no, void *arg0) {
    pushl(arg0);
    pushl(&syscall_no);

    printf("%s\n", (char*)(get_esp()+8));

    interrupt_handler();
    addl_esp(16);
    return get_eax();
}

// TODO 2: 새로운 syscallN 만들기