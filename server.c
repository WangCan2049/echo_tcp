/*Required Headers*/
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);

    bind(listen_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    listen(listen_fd, 10);

    int come_fd = accept(listen_fd, (struct sockaddr *)NULL, NULL);

    char buf[100];
    while (1)
    {
        bzero(buf, 100);
        read(come_fd, buf, 100);
        printf("send:\t%s", buf);
        write(come_fd, buf, strlen(buf) + 1);
    }
}