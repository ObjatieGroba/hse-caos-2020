#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char ** argv) {
    time_t now;
    time(&now);
    printf("%ld\n", now / 60 / 60 / 24 / 365);

    long * y;
    short * x = (short*)y;
    struct tm * res = localtime(&now);
    printf("%04d\n", res->tm_year + 1900);

    struct stat meta;
    if (lstat(argv[1], &meta) == 0) {
        if (S_ISREG(meta.st_mode)) {
            printf("REGULAR\n");
        }
        if (S_ISDIR(meta.st_mode)) {
            printf("DIRECTORY\n");
        }
        if (S_ISLNK(meta.st_mode)) {
            printf("LINK\n");
        }
    } else {
        printf("ERROR\n");
    }
//    stat("a.txt", &meta);

}
