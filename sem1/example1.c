#include "stdio.h"
#include "stdlib.h"

// int main() {
// int main(int argc, const char * argv[]) {
int main(int argc, char ** argv) {
    int x;
    long y;
    int scanned = scanf("%d %ld", &x, &y);
    if (scanned != 2) {
        return 1; /// 1llu 1l 1ll ...
        // exit(1);
    }

    printf("%d %d %ld\n", scanned, x, y);

    int c_in;
    // c_in = getc(stdin);
    while ((c_in = getc(stdin)) != EOF) { // c_in != EOF
        char c = (char)c_in;
        /// ...
    }

    float f;
    double d;

    return 0;
}
