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

#include <pthread.h>

void * thread_func(void * ptr) {
    printf("Hello world!\n");
    printf("%d\n", (int)(intptr_t)ptr);
    return NULL;
}


int main(int argc, char ** argv) {// , const char *envp[]) {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, (void*)(intptr_t)1);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}
