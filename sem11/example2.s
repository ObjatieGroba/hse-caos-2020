#include <asm/unistd_32.h>
        .text
        .global _start


process:

        movl   $__NR_read, %eax
        movl   $0, %ebx
        movl   A, %ecx
        movl   1, %edx
        int    $0x80
        ret

_start:
        call process
        movl   $__NR_exit, %eax
        movl   $3, %ebx
        int    $0x80

        .data
A:      .int   0
