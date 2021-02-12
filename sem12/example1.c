#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char ** argv) {
//    for (int argn = 0; argn != argc; ++argn) {
//        printf("%s\n", argv[argn]);
//    }
//
//    printf("---END---\n");

//    int fd = open(argv[1], O_WRONLY | O_CREAT, 0600);
    int fd = open("myfile.txt", O_WRONLY | O_CREAT, 0600);

    off_t pos = lseek(fd, 3, SEEK_CUR);
    pos = lseek(fd, 0, SEEK_CUR);

    printf("%ld\n", pos);

    printf("%d %zd \n", fd, write(fd, "yy", 2));

    close(fd);
}
