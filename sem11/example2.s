#include <asm/unistd_32.h>
        .text
        .global _start

_start:
        movl   $__NR_exit, %eax
        movl   $3, %ebx
        int    $0x80
