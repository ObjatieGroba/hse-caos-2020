#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


/**
 * int (* func_returns_func2(double, char (*f)(char)))(int);
 *
 * Указатель на функцию, которая возвращает эту функцию и принимает float
 */

char charfunc(char c) {
    printf("charfunc\n");
    return c;
}

int intfunc(int i) {
    printf("intfunc\n");
    return i;
}

int (*func_returns_func2(double d, char (*f)(char)))(int) {
    printf("func_returns_func2\n");
    f('a');
    return intfunc;
}

int (*(*func_returns_func2_ptr(float f))(double, char (*f)(char)))(int) {
    printf("func_returns_func2_ptr\n");
    return func_returns_func2;
}

int main(void) {
    func_returns_func2_ptr(1.f)(1, charfunc)(1);
    return 0;
}

