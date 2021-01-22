        .text         /* секция кода программы */
        .global process

process:
        /* 4(%esp) == 1 */

        /* Пролог */
        push    %ebp
        movl    %esp, %ebp

        /* 8(%esp) == 1 */

        /* 8(%ebp) == 1 !!! Лучше так, ebp неподвижен */

        movl    8(%ebp), %eax
        xorl    12(%ebp), %eax

        /* Эпилог */
        popl    %ebp
        ret

