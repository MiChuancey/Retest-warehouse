//
// Created by Administrator on 2021/3/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <unistd.h>
#include "transferData.h"

static void printErr(char* msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sd = socket(AF_INET,SOCK_DGRAM,0);
    if(sd<0) printErr("socket");
    struct sockaddr_in serverAddr;

    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(SERPORT);
    serverAddr.sin_family = AF_INET;

    if (bind(sd,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0) printErr("bind");
    while (1) {
        puts("server is waiting connection!");
        struct MSG msg;
        struct sockaddr_in clientAddr;
        socklen_t len = sizeof (clientAddr);   //一定要初始化
        int recvMsg = recvfrom(sd,&msg,sizeof(msg),0,(struct sockaddr*)&clientAddr,&len);
        if (recvMsg < 0) printErr("recvMsg");
        puts("msg received!");
        printf("%s:%s\n",msg.name,msg.msg);
        char msgInfo[MSGLEN];
        printf("client infomation:%s:%d\n",inet_ntop(AF_INET,&clientAddr.sin_addr.s_addr,msgInfo,sizeof(clientAddr)),ntohs(clientAddr.sin_port));
    }


    return 0;
}