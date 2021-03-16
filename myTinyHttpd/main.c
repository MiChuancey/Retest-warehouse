#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/ip.h> /* superset of previous */
#include <unistd.h>
#include <string.h>
#include "serverParameter.h"
#include <ctype.h>

int startup(u_short*);
void* acceptRequest(void*);
void errExit(char*);
void unimplemented(int);

void errExit(char* func) {
    perror(func);
    exit(1);
}

void unimplemented(int client) {

}

/**
 * create server socket and listening the port.
 * Parameters:server port
 * Returns: the server socket
 * */
int startup(u_short* port) {
    int httpd = socket(AF_INET,SOCK_STREAM,0);
    if (httpd < 0) errExit("socket");
    struct sockaddr_in serverAddr;
    memset(&serverAddr,0,sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(*port);

    //setsockopt
    int optVal =1;
    if (setsockopt(httpd,SOL_SOCKET,SO_REUSEADDR,&optVal,sizeof(optVal))<0) errExit("setsockopt");
    if (bind(httpd,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0) errExit("bind");

    // if port is zero,then allocating a port dynamically
    if (*port==0) {
        socklen_t len = sizeof (serverAddr);
        if (getsockname(httpd,(struct sockaddr*)&serverAddr,&len)<0) errExit("getsockname");
        *port = ntohs(serverAddr.sin_port); //save port name designated by kernel automatically
    }
    if (listen(httpd,MAXCONNECTIONNUM)<0) errExit("listen");
}

/**
 * create a thread to accept on the port
 * Parameters: the socket connected to the client
 * */
void* acceptRequest(void* arg){
    int clientSock = *(int*)arg;
    char* buf;
    size_t bufLen=0;
    FILE* fp = fdopen(clientSock,"r");
    if (fp==NULL) errExit("fdopen");
    ssize_t numChars = getline(&buf,&bufLen,fp);
    if (numChars<0) errExit("getline");

    //parse request parameters
    char method[255];
    int i=0,j=0;
    while (!isspace(buf[i])&&i+1<sizeof(method)) {
        method[i]=buf[i];
        i++;
    }
    method[i]='\0'; //get method
    j=i;

    if (strcasecmp(method,"GET")!=0&&strcasecmp(method,"POST")!=0) { //request error
        unimplemented(clientSock);
        return NULL;
    }

    if (strcasecmp(method,"POST")==0) { //POST

    }

}


int main(int argc,char** argv) {
    u_short port = SERVERPORT;
    int serverSock = startup(&port); //创建服务器socket
    printf("myHttpd is running on port %d\n",port);

    while (1) {
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        int clientSock = accept(serverSock,(struct sockaddr*)&clientAddr,&clientAddrLen);
        if (clientSock < 0) errExit("accept");
        pthread_t pthread;
        if (pthread_create(&pthread,NULL,acceptRequest,&clientSock)!=0)
            perror("pthread_create");

    }
    close(serverSock);
    return 0;
}
