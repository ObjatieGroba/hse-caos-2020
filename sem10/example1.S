        .text         /* секция кода программы */
        .global process

process:
        /* Пролог */
        push    %ebp
        movl    %esp, %ebp

        movsd   8(%ebp), %xmm1

        mulsd   %xmm1, %xmm1

        sub     $8, %esp        // резервируем память
        movsd   %xmm1, (%esp)   // копируем значение double из %xmm0 в стек
        fldl    (%esp)          // загружаем из стека на %st(0)
        add     $8, %esp        // очищаем стек

        /* Эпилог */
        popl    %ebp
        ret
