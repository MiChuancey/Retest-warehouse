//
// Created by Administrator on 2021/3/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include "transferData.h"

int main() {
    int sd = socket(AF_INET,SOCK_DGRAM,0);
    if (sd < 0) {
        perror("scoket");
        exit(1);
    }
    struct sockaddr_in  localAddr;
    localAddr.sin_family = AF_INET;
    localAddr.sin_port = htonl(SERPORT);
    inet_pton(AF_INET,"0.0.0.0",&(localAddr.sin_addr.s_addr));
    if(bind(sd,(void *)&localAddr,sizeof(localAddr)) < 0 ) {
        perror("bind()");
        exit(1);
    }
    while (1){
        struct MSG recvMsg;
        struct sockaddr_in remoteAddr;
        socklen_t remoteSockLen;
        if(recvfrom(sd,&recvMsg,sizeof(recvMsg),0,(void *)&remoteAddr,&remoteSockLen)<0) {
            perror("recvfrom");
            exit(1);
        }
        printf("succeed\n");
    }

    return 0;
}