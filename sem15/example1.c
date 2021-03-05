#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int func(int x);

int main(int argc, char ** argv) {
    '\0'; // Zero symbol

    printf("%d\n", func(0));
}
