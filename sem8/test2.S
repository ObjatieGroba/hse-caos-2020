        .text         /* секция кода программы */
        .global main  /* экспортируем точку входа - функцию main */
main:
        movl    $20, A
        movl    $10, B

        call    process

        movl    B, %eax

        call    writei32
        call    nl
        call    finish





