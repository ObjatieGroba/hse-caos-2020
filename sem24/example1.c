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

//int flag = 0;
//
//int accaount = 0;
//
//int compare_and_swap(int *val, int expected, int new_val);
//
//void f() {
////    while (flag != 0) {
////        /// Wait
////    }
////    flag = 1;
//    while (!compare_and_swap(&flag, 0, 1)) {
//        ;
//    }
//
//    /// Crit
//    int old_val = accaount;
//    int new_val = old_val + 1;
//    accaount = new_val;
////    accaount += 1;
//
//    flag = 0;
//}

//void * thread_func(void * ptr) {
//    for (int i = 0; i != 10000; ++i) {
//        if (i % 2 == 0) {
//            pthread_mutex_lock(&mutex1);
//            pthread_mutex_lock(&mutex3);
//            /// Crit
//            value += (int) (intptr_t) (ptr);
//
//            pthread_mutex_unlock(&mutex1);
//            pthread_mutex_unlock(&mutex3);
//        }
//        if (i % 2 == 1) {
//            pthread_mutex_lock(&mutex3);
//            pthread_mutex_lock(&mutex1);
//            /// Crit
//            value += (int) (intptr_t) (ptr);
//
//            pthread_mutex_unlock(&mutex1);
//            pthread_mutex_unlock(&mutex3);
//        }
//    }
//    return NULL;
//}


pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t c = PTHREAD_COND_INITIALIZER;

int value = 0;

void * thread_func1(void * ptr) {
    pthread_mutex_lock(&mutex1);

    value = 1;

    pthread_cond_signal(&c); // - буди одного

//    pthread_cond_broadcast(&c); // - буди всех

    pthread_mutex_unlock(&mutex1);
}

void * thread_func2(void * ptr) {
    pthread_mutex_lock(&mutex1);

    if (value == 0) {
        /// Нет данных - ждем
        pthread_cond_wait(&c, &mutex1); /// отпускает, ждет, берет мьютекс
    }

    int lv = value;

    pthread_mutex_unlock(&mutex1);

    printf("value %d\n", lv);
}


int main(int argc, char ** argv) {// , const char *envp[]) {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_func2, (void*)(intptr_t)-2);
    pthread_create(&thread2, NULL, thread_func1, (void*)(intptr_t)1);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("%d\n", value);
}
