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

int main(int argc,char* argv[]) {
    if(argc < 2){
        fprintf(stderr,"Usage....\n");
        exit(1);
    }

    struct MSG msgT;
    strcpy(msgT.name,argv[1]);
    char m[MSGLEN];
    sprintf(m,"hello i am %s, i am calling you\n",argv[1]);
    strcpy(msgT.msg,m);

    int sd = socket(AF_INET,SOCK_DGRAM,0);
    if(sd<0) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in serverAddr;
    serverAddr.sin_port = htonl(SERPORT);
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET,"127.0.0.1",&serverAddr.sin_addr);

    if (connect(sd,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0) {
        perror("connect");
        exit(1);
    }
    if (send(sd,&msgT,sizeof(msgT),0)<0) {
        perror("send");
        exit(1);
    }
//    if (sendto(sd,&msgT,sizeof(msgT),0,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0) {
//        perror("sendto");
//        exit(1);
//    }

    return 0;
}
