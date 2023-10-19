#include "intr.h"
#include "kernel.h"
#include "global.h"
#include "privileged.h"
#include <stdlib.h>

struct intr_frame{
    int eax;
    void* esp;
};

// Function to handle system calls
void syscall_handler(struct intr_frame *f) {
    // TODO 1 : syscall_handler 구현하기
    int syscall_no = *(int*)(f->esp);

    if (syscall_no == SYS_AA) {
        void *arg = *(char **)(f->esp + 8);
        kernel_function(arg);
    }
}

// Function to handle interrupts
void interrupt_handler() {
    
    if(get_cpu_mode() != USER_MODE)
        kernel_panic();

    switch_to_kernel_mode();
    
    struct intr_frame *f = (void*)malloc(sizeof(struct intr_frame));
    f->eax = get_eax();
    f->esp = get_esp();

    syscall_handler(f);

    movl_eax(f->eax);
    free(f);

    switch_to_user_mode();

    if(get_cpu_mode() != USER_MODE)
        kernel_panic();
}