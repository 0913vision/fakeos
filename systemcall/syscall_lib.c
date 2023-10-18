#include "syscall_lib.h"
#include "syscall.h"
#include "global.h"

void aa(char *msg) {
    syscall1(SYS_AA, msg);
}
