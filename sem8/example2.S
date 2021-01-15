        .text         /* секция кода программы */
        .global process

process:
        movl    B, %eax
        movl    %eax, A
        movl    $1, B
        ret

        .data         /* секция данных программы */
A:      .int    0
B:      .int    0
        .global A,B




















