#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(int argc, const char ** argv) {
    printf("HERE:\n");
    for (int i = 0; i < argc; ++i) {
        printf("%s\n", argv[i]);
    }
}
