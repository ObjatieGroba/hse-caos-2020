        .text         /* секция кода программы */
        .global main  /* экспортируем точку входа - функцию main */
main:
        call    readi32
        movl    %eax, %ebx
        call    readi32
        subl    %ebx, %eax

        call    label

        call    writei32
        call    nl
        call    finish


label:
        nop
        ret

