#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char ** argv) {
//    pid_t first = getpid();

    printf("Hell");
    fflush(stdout);

    pid_t pid = fork();
    if (pid < 0) { // pid == -1
        // Error
        return 2;
    }

    if (pid == 0) {
        // Child
    } else {
        // Parent, pid is the Child process id
//        int status;
//        waitpid(pid, &status, 0);
//        waitpid(pid, NULL, 0);
        wait(NULL);
    }
    printf("%d\n", pid);
}
