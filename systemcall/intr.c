#include "intr.h"
#include "kernel.h"
#include "global.h"
#include "privileged.h"

struct intr_frame{
    unsigned int eax;
    unsigned int esp;
};

// Function to handle system calls
void syscall_handler(struct intr_frame *f) {
    // TODO 1 : syscall_handler 구현하기
    int syscall_no = *((int *)(memory + f->esp));
    f->esp += sizeof(int);

    if (syscall_no == SYS_AA) {
        char *arg = (char *)(memory + f->esp);
        f->esp += strlen(arg)+1;

        kernel_function(arg);
    }
}

// Function to handle interrupts
void interrupt_handler() {
    
    if(get_cpu_mode() != USER_MODE)
        kernel_panic();

    switch_to_kernel_mode();
    
    struct intr_frame *f = (void*)malloc(sizeof(struct intr_frame));
    f->eax = cpu.eax;
    f->esp = cpu.esp;

    syscall_handler(f);

    cpu.eax = f->eax;
    cpu.esp = f->esp;
    free(f);

    switch_to_user_mode();

    if(get_cpu_mode() != USER_MODE)
        kernel_panic();
}