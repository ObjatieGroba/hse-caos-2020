#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

enum {
    x = 18262836719819ll,  // 1ull << 40
    y = 0xffff00ff,
    z = 1u,
};

int f(int x) {
    if (x) {
        return 1;
//    } else {
//        return 0;
    }
    return 0;
}

/*#include <stdio.h>
#include <string.h>*/
// Ban


int main(int argc, char ** argv) {
//    x << 1;
    unsigned x = 0;

//    ~x;

    uint32_t fff = ~0; /// need Cast

    uint64_t ggg = -3; /// same as (uint64_t)0 - 3

    printf("%lu\n", ggg);

    int state = 2345;  /// BAN

    if (state == 2345) {  /// BAN
    }

    typedef unsigned UTYPE;  /// PLEASE DO IT GLOBALLY

    char buf[10] = "avx";
    buf[0] = '%';
    buf[1] = 'd';
    buf[2] = '\0';
    scanf("%9s\n", buf);
    printf(buf, 11234567);

    printf(" My string\n");

    char * ptr0;

    const char * ptr1 = NULL;
    ++ptr1;

    char const * ptr2 = NULL;
    ++ptr2;

    char * const ptr3 = NULL;
//    ++ptr3;

    const char * const ptr4 = NULL;
}

