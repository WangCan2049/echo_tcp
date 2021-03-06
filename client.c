#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof servaddr);

    char serverIp[32];
    strcpy(serverIp,argv[1]);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(22000);
    inet_pton(AF_INET, serverIp, &(servaddr.sin_addr));

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    char sendline[100];
    char recvline[100];
    while (1)
    {
        bzero(sendline, 100);
        bzero(recvline, 100);
        fgets(sendline, 100, stdin); /*stdin = 0 , for standard input */

        write(sockfd, sendline, strlen(sendline) + 1);
        read(sockfd, recvline, 100);
        printf("get:\t%s", recvline);
    }
}