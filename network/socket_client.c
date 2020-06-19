#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/wait.h>
#include<netdb.h>

static int connect_server(const char* hostname, uint16_t port)
{
    struct addrinfo hints, *res, *ressave;
    int n, sockfd;
    char port_str[16];

    sprintf(port_str, "%u", port);
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC; //IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;
    //hints.ai_flags = AI_PASSIVE;//add my IP

    n = getaddrinfo(hostname, port_str, &hints, &res);
    if(n<0) {
        fprintf(stderr, "getaddrinfo error:: [%s]\n", gai_strerror(n));
        return -1;
    }
    ressave = res;

    sockfd = -1;
    while(res) {
        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        struct sockaddr_in client;
        client.sin_family = AF_INET;
        client.sin_addr.s_addr = htonl(INADDR_ANY);
        client.sin_port = htons(8301);

        int opt = 1;
        setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void*)&opt, sizeof(opt));
        if(bind(sockfd, (struct sockaddr*)&client, sizeof(client)) == -1) {
            printf("bind() failed\n");
            close(sockfd);
            sockfd = -1;
        }
        if(!(sockfd<0)) {
            if(connect(sockfd, res->ai_addr, res->ai_addrlen) == 0)
                break;
            close(sockfd);
            sockfd = -1;
            printf("connect failed\n");
        }
        res = res->ai_next;
    }
    freeaddrinfo(ressave);
    return sockfd;
}

int main(int argc, char *argv[])
{
    if(argc!=3) {
        printf("please input hostname\n");
        return 0;
    }
    int ret = connect_server(argv[1], atoi(argv[2]));
    printf("ret: %d\n", ret);
    return 0;
}
