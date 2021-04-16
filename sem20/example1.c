#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

void process(int sig) {
    printf("Signal\n");
    exit(3);
}



int main(int argc, char ** argv) {// , const char *envp[]) {
    printf("%d\n", getpid());
//    signal(SIGINT, process); ///  (SIGINT);
//    printf("%d\n", getpid());

    struct sigaction new_action, old_action;

    new_action.sa_handler = process;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;

//    sigaction(SIGINT, NULL, &old_action);
//    sigaction(SIGINT, &new_action, NULL);

    sigaction(SIGINT, &new_action, &old_action);


    while (1) {
//        pause();
//        printf("text\n");
    }
}
