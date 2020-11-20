#include "stdio.h"
#include "stdlib.h"
#include "inttypes.h"


struct Struct {
    int x;
    int y;
};

struct Struct2 {
    struct Struct s;
    int z;
};

/// Does NOT working
struct OurDouble {
    uint64_t s : 1;
    uint64_t e : 11;
    uint64_t m : 52;
};

union DoubleUn {
    struct OurDouble od;
    double d;
};

union Un2 {
    double d;
    uint64_t u;
};

int main(int argc, char ** argv) {
    struct Struct x;
    x.x; /// ???

    double d = 1.08;
    struct OurDouble* od = (struct OurDouble *)(&d); /// Not NICE
//    ((void (*)(void))(&d)) ();
    printf("%llu %llu %llu\n", od->s, od->e, od->m);

    union DoubleUn dun;
    dun.d = 1;
    printf("%d\n", dun.od.e);

    union Un2 un2;
    un2.d = -1.002;
    printf("%llu\n", un2.u);

    printf("%llu\n", un2.u >> 63u);

    1; /// int
    1u; /// unsigned int
    1llu; /// unsigned long long

    un2.u & ((1u << 8u) - 1u); /// Last 8 bits

    (un2.u >> 7u) & ((1u << 8u) - 1u); /// Bits from 15 to 7
}
