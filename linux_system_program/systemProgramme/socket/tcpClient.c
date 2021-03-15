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
#include <string.h>

static void printErr(char* func) {
    perror(func);
    exit(1);
}

int main(int argc,char** argv) {
    if (argc<2) {
        fprintf(stderr,"Usage.....\n");
        exit(1);
    }
    int sd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (sd < 0) printErr("socket");
    struct sockaddr_in serverAddr;
    serverAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    serverAddr.sin_port = htons(SERPORT);
    serverAddr.sin_family = AF_INET;
    if (setsockopt(sd,SOL_SOCKET,SO_BINDTODEVICE,NULL,0)<0) printErr("setsockopt"); //绑定使用网卡

    if (connect(sd,(struct sockaddr*)&serverAddr,sizeof (serverAddr)) < 0) printErr("connect");
    struct MSG msg;
    strcpy(msg.name,argv[1]);
    strcpy(msg.msg,argv[2]);
    if(send(sd,&msg,sizeof (msg),0) < 0) printErr("send");
    close(sd);

    return 0;
}