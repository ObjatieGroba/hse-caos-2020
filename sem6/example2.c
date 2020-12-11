#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

typedef int MyInt;

typedef void (*MyFunc) ();

struct X {
//    void (*func) (void);
    const char * name;
    MyFunc func;
};

static void test(void) {
    printf("Test called");
}

struct X funcs[] = {
        {"test", test},
        {"test2", test}
};

MyFunc get() {
    return test;
}

void run() {
    return get()(1.0);

    // get()(1.0)
    // return
}

MyFunc (*func2)(void);

//return_type (*name) (typearg1 arg1, ...)

int (* func_returns_func(double))(int);

int run2() {
    double d;
    int (*rf)(int) = func_returns_func(d);
    int res = rf(2);
    return res;
}

int (* func_returns_func2(double, char (*f)(char)))(int);


int main(int argc, const char ** argv) {
    /// BAD
//    const char * s = "xyz";
//    void (*func) (void) = s;
//    func();

    struct X x;
    x.func = test;
    x.name = "sin";

    x.func();

    sin(1);
}
