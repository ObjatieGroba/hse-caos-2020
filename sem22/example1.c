#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <inttypes.h>

#include <sys/signal.h>
#include <sys/time.h>

volatile int counter = 0;

void alrm(int sig) {
    ++counter;
}

int main(int argc, char ** argv) {// , const char *envp[]) {
    signal(SIGALRM, alrm);

    struct timeval tv = {};
    tv.tv_sec = 1;
    tv.tv_usec = 1;

    struct timeval ti = {};
    ti.tv_sec = 0;
    ti.tv_usec = 500000;

    struct itimerval to = {};
    to.it_value = tv;
    to.it_interval = ti;

    setitimer(ITIMER_REAL, &to, NULL);

    while (1) {
        if (counter == 5) {
            return 0;
        }
//        pause();
    }
}
