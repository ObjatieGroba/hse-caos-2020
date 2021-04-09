#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>



int main(int argc, char ** argv) {// , const char *envp[]) {
    /// KEY=val
//    pid_t first = getpid();

//    printf("Hell");
//    fflush(stdout);

    int pipefd[2];
    pipe(pipefd);

    pid_t pid = fork();
    if (pid < 0) { // pid == -1
        // Error
        return 2;
    }

    if (pid == 0) {
        // Child
        close(pipefd[0]);
        while (1) {
            write(pipefd[1], "str", 3);
            break;
        }
        close(pipefd[1]);
    } else {
        // Parent, pid is the Child process id
        close(pipefd[1]);
        char buf[1024];
        while (1) {
            ssize_t num = read(pipefd[0], buf, sizeof(buf) - 1);
            printf("Read %ld\n", num);
            if (num <= 0) {
                break;
            }
            buf[num + 1] = '\0';
            printf("%s\n", buf);
        }
        close(pipefd[0]);
        int status;
        wait(&status);
    }
    printf("%d\n", pid);
}
