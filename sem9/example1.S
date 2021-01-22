        .text         /* секция кода программы */
        .global process

process:
        /* Пролог */
        push    %ebp
        movl    %esp, %ebp

        /* Формируем аргументы и вызываем */
        pushl   A
        pushl   $format
        call    printf

        /* Очистка стека */
        addl    $8, %esp
        /* popl    %e... (x2) */
        /* movl    %ebp, %esp */

        /* Эпилог */
        popl    %ebp
        ret

        .data         /* секция данных программы */
format: .asciz  "%d\n"
