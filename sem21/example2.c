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
    int fd = socket(PF_INET, SOCK_STREAM, 0);

    int val = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

    struct sockaddr_in s1;
    s1.sin_family = AF_INET;
    s1.sin_port = htons(8080);
    s1.sin_addr.s_addr = INADDR_ANY;

    if (bind(fd, (struct sockaddr*)&s1, sizeof(s1)) < 0) {
        return 1;
    }

    listen(fd, 5);

    struct sockaddr_in s2;
    socklen_t slen = sizeof(s2);
    int fd_client = accept(fd, (struct sockaddr*)&s2, &slen);

    FILE * fin = fdopen(dup(fd_client), "r");
    FILE * fout = fdopen(fd_client, "w");


    char buf[1024];
    fscanf(fin, "%1000s", buf);
    fprintf(fout, "%s", buf);
    printf("%s", buf);



    close(fd_client);
    close(fd);
}
