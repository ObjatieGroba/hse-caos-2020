#include <asm/unistd_32.h>

enum {
    stdin = 0,
    stdout = 1,
    stderr = 2
};

int read(char * buf, unsigned size) {
    int num;
    asm volatile (
            "movl   %1, %%eax\n"
            "movl   %2, %%ebx\n"
            "movl   %3, %%ecx\n"
            "movl   %4, %%edx\n"
            "int    $0x80\n"
            "movl   %%eax, %0\n"
            : "=g" (num)
            : "g"(__NR_read), "g" (stdin), "g"(buf), "g" (size)
            : "%eax", "%ebx", "%ecx", "%edx", "memory"
            );
//    asm volatile (
//            "movl   %[syscall], %%eax\n"
//            "movl   %[arg1], %%ebx\n"
//            "movl   %[arg2], %%ecx\n"
//            "movl   %[arg3], %%edx\n"
//            "int    $0x80\n"
//            "movl   %%eax, %[out1]\n"
//            : [out1] "=g" (num)
//            : [syscall] "g"(__NR_read), [arg1] "g" (stdin), [arg2] "g"(buf), [arg3] "g" (size)
//            : "%eax", "%ebx", "%ecx", "%edx", "memory"
//            );
    return num;
}

int write(const char * buf, unsigned size) {
    ;;;
}

void _start() {
    char buf[1024];
    int x = read(buf, sizeof(buf));
    asm volatile (
//            "movl    %0, %%eax\n"
            "movl    %1, %%ebx\n"
            "int     $0x80\n"
            :
            : "a" (__NR_exit), "rm" (x)
            : "%ebx"
            );
}
