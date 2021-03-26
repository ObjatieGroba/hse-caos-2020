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

    pid_t pid = fork();
    if (pid < 0) { // pid == -1
        // Error
        return 2;
    }

    if (pid == 0) {
        // Child
        int fdin = open(argv[2], O_RDONLY);
        // dup2(fdin, 0)
        close(STDIN_FILENO);
        dup(fdin);
        close(fdin);
        execlp(argv[1], argv[1], NULL); // == -1;
        /// execlp("/bin/sh", "/bin/sh", "-c", ....);
    } else {
        // Parent, pid is the Child process id
//        int status;
//        waitpid(pid, &status, 0);
//        waitpid(pid, NULL, 0);
//        wait(NULL);
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            int ret_code = WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            int sig_num = WTERMSIG(status);
        }
    }
    printf("%d\n", pid);
}
