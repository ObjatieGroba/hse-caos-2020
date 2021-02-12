#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

ssize_t force_write(int fd, const char *buf, size_t size) {

}

int main(int argc, char ** argv) {
    int fd_in = 0;
    int fd_out = 1;

    char buf[4096];

    while (1) {
        errno = 0;
        ssize_t r_res = read(fd_in, buf, sizeof(buf));
        if (r_res == 0) {
            /// End of stream
            return 0;
        } else if (r_res < 0) {
            fprintf(stderr, "read %zd (%d)\n", r_res, errno);
            return 1;
        }
        /// CALL force_write
        ssize_t w_res = write(fd_out, buf, (size_t)r_res);
        if (w_res < 0) {
            fprintf(stderr, "write %zd\n", w_res);
            return 1;
        }
//        if (w_res < r_res) {
//            w_res = write(fd_out, buf + w_res, (size_t)r_res - w_res);
//        }
    }
}
