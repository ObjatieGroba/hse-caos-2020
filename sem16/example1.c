#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(int argc, char ** argv) {
    int fd = open("in.txt", O_RDWR);// | O_CREAT | O_TRUNC);
    struct stat st;
    fstat(fd, &st);
    while (1) {
        ;
    }
    char * p = mmap(0, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    p[10] = '\0';
    printf("%s", p);
    munmap(p, st.st_size);
}
