#include "stdio.h"
#include "stdlib.h"


// BAN
// #define CONST2 3

enum {
    BASE = 7
};

struct Struct {
    int x;
    int y;
};

int main(int argc, char ** argv) {
//    char * buf = "123 ";
//    int i;
//    itoa(i, buf, 10);
//    printf("%d\n", i);
    /// use snprintf except of itoa

    /// Not const
    const int CONST = 1;

    BASE;

    /// BAN
    if (1)
        return 0;

    /// BAN
    if (0) return 1;

    /// NICE
    if (2) {
        return 1;
    }
}


