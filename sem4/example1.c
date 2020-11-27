#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(int x) {
    if (x % 2 == 0) {
        return x / 2;
    }
//   } else if (x % 3 == 0) {
    if (x % 3 == 0) {
        return x / 3;
    }
    return x - 1;
//    } else {
//        return x - 1;
//    }
}

int func2() {
    int x = -1;
    unsigned y = 1u << 31;
    // if (x & y)  // ???
    y >> 1; /// check
    y >> 2; /// check

    unsigned f = y;
    while (f) {
        /// Last bit
        f >>= 1u;
    }
    return 0;
}

int mystrlen(const char * s) {
    if (s == NULL) {
        return 0;
    }
    int len = 0;
    while (*s) {
        ++s;
        ++len;
    }
    return len;
}

int main(int argc, char ** argv) {
    '\0';
    '0';
    '\n';
    '\r';

    char * str = "1235";
    if (str[5] != 0) { /// or !str[5];
        ///
    }

    str[5] == *(str + 5);

    char buf[5];
    int x = 1;
    sizeof(buf) == 5;

    /// bbbbb___xxxx

//    scanf("%ms", &str);
//
//    strncpy(buf, str, min(strlen(str), sizeof(buf) - 1));
//
//    printf("%s, %d\n", str, x);

    signed char sc;
    unsigned char uc;
    char c; /// ???

    char * xxx = malloc(10); /// TODO free
    /// in c++ scope guard free
    xxx = 0;

    if (xxx[0]) {
        free(xxx);
        return 0;
    }

    free(xxx);
}
