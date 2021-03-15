//
// Created by Administrator on 2021/3/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transferData.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <unistd.h>

static void printErr(char* msg) {
    perror(msg);
    exit(1);
}

void generateMsgData(struct MSG* msg,char *argv[]) {
    strcpy(msg->name,argv[1]);
    strcpy(msg->msg,argv[2]);
//    msg->ip = htonl(INADDR_LOOPBACK);
//    msg->port = htonl()
}

int main(int argc,char* argv[]) {
    if(argc < 2) fprintf(stderr,"Usage.......\n");

    int sd = socket(AF_INET,SOCK_DGRAM,0);
    if (sd < 0) perror("socket");

    struct sockaddr_in serverAddr;
    serverAddr.sin_port = htons(SERPORT);
    serverAddr.sin_addr.s_addr = inet_addr(SEIP);
    serverAddr.sin_family = AF_INET;

    struct MSG msg;

    generateMsgData(&msg,argv);
    int len = sizeof(msg);


    if(sendto(sd,&msg,len,0,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0)
        printErr("sendto");
    puts("succeed!");

    close(sd);

    return 0;
}
