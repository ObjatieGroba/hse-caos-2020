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


int main(int argc, char ** argv) {// , const char *envp[]) {
    struct addrinfo hints = {};
    struct addrinfo * result;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;
    int err = getaddrinfo("google.com", "http", &hints, &result);
    if (err) {
        printf("Error: %s\n", gai_strerror(err));
    } else {
        struct sockaddr_in * ain = result->ai_addr;
        result->ai_next;
        printf("%" PRIu32 "\n", ntohl(ain->sin_addr.s_addr));
        printf("%s\n", inet_ntoa(ain->sin_addr));
        printf("%" PRIu16 "\n", ntohs(ain->sin_port));

        int fd = socket(PF_INET, SOCK_STREAM, 0);
        int c = connect(fd, result->ai_addr, result->ai_addrlen);

        FILE * fin = fdopen(dup(fd), "r");
        FILE * fout = fdopen(fd, "w");

        fprintf(fout, "GET / HTTP/1.1\n"
                      "Host: google.com\n\n\n\n");

        fflush(fout);
        char buf[1024];
        fscanf(fin, "%1000s", buf);
        printf("%s", buf);
        fscanf(fin, "%1000s", buf);
        printf("%s", buf);
        fscanf(fin, "%1000s", buf);
        printf("%s", buf);
        fscanf(fin, "%1000s", buf);
        printf("%s", buf);
        fscanf(fin, "%1000s", buf);
        printf("%s", buf);
        fscanf(fin, "%1000s", buf);
        printf("%s", buf);

        freeaddrinfo(result);
    }
}
