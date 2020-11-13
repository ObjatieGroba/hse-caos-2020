#include "stdio.h"
#include "stdlib.h"
#include <inttypes.h>


int func(int a, int b) {
    if (b == 0) {
        return a;
    }
    if (b == 1)
        return a - 1;
    return a - b;
}


int main(int argc, char ** argv) {
    int x = 1, y = 2;
    if (scanf("%d", &x) != 1) {
        fprintf(stderr, "Can not read x\n");
        return 1; // 2, 3 ...
    }
    // x * y
    // (long long)x * (long long)y;
    (long long) x * y;

    /// File *  -  stdin stdout stderr

    uint32_t a;
    uint16_t b;
    scanf("%" SCNu32 " %" SCNd16, &a, &b);
    // scanf("%" "u" " %" "hd", &a, &b);
    // scanf("%u %hd", &a, &b);
    a += b;
    fprintf(stderr, "%" PRIu32, a);

    (uint32_t)0;
    uint32_t var = 0;

    1u & 0llu;


}
