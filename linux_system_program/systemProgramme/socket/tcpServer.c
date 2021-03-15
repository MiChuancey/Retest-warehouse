//
// Created by Administrator on 2021/3/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include "transferData.h"

static void printErr(char *func) {
    perror(func);
    exit(1);
}

int main(int argc,char** argv) {
    int sd = socket(AF_INET,SOCK_STREAM,0);
    if (sd < 0) printErr("socket");
    struct sockaddr_in serAddr;
    serAddr.sin_port = htons(SERPORT);
    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sd,(struct sockaddr*)&serAddr,sizeof (serAddr))<0) printErr("bind");

    if (listen(sd,MAXCONNECTION)<0) printErr("listen");

    while (1) {
        struct sockaddr_in clientAddr;
        socklen_t len = sizeof (clientAddr);
        int fd = accept(sd,(struct sockaddr*)&clientAddr,&len);
        puts("one client connected");
        if (fd < 0) printErr("accept");
        struct MSG msg;
        if (recv(fd,&msg,sizeof (msg),0)<0) printErr("recv");
        printf("%s\n",msg.name);
        close(fd);
    }


    return 0;
}
