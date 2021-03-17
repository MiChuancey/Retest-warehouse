#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/ip.h> /* superset of previous */
#include <unistd.h>
#include <string.h>
#include "serverParameter.h"
#include <ctype.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

int startup(u_short*);
void* acceptRequest(void*);
void serveFile(int,const char*);
void executeCgi(int,const char*,const char*,const char*);
void sendHeader(int,const char*);
void cat(int,FILE*);

int getLine(int,char*,int);
void errExit(char*);
void unimplemented(int);
void notFound(int);
void badRequest(int);
void cannotExecute(int);


void errExit(char* func) {
    perror(func);
    exit(1);
}

/**
 * request method not support
 * */
void unimplemented(int clientSock) {
    char buf[BUFFSIZE];
    strcpy(buf,"HTTP/1.0 501 Method Not Implemented\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,SERVERINFO);
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"Content-Type: text/html\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"<HTML><HEAD><TITLE>Method Not Implemented\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"</TITLE></HEAD>\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"<BODY><P>HTTP request method not supported.\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"</BODY></HTML>\r\n");
    send(clientSock,buf,strlen(buf),0);
}

/**
 * request url not exists
 * */
void notFound(int clientSock) {
    char buf[BUFFSIZE];
    strcpy(buf,"HTTP/1.0 404 NOT FOUND\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,SERVERINFO);
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"Content-Type: text/html\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"<HTML><TITLE>Not Found</TITLE>\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"<BODY><P>The server could not fulfill\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"your request because the resource specified\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"is unavailable or nonexistent.\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"</BODY></HTML>\r\n");
    send(clientSock,buf,strlen(buf),0);
}

void badRequest(int clientSock) {
    char buf[BUFFSIZE];
    strcpy(buf,"HTTP/1.0 400 BAD REQUEST\\r\\n\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"Content-type: text/html\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"<P>Your browser sent a bad request, ");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"such as a POST without a Content-Length.\r\n");
    send(clientSock,buf,strlen(buf),0);
}

void cannotExecute(int clientSock) {
    char buf[BUFFSIZE];
    strcpy(buf,"HTTP/1.0 500 Internal Server Error\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"Content-type: text/html\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"<P>Error prohibited CGI execution.\r\n");
    send(clientSock,buf,strlen(buf),0);
}

/**
 * read a line from sock
 * parameters:
 *  sock:fd
 *  buf: save data read from sock
 *  size: data size read form sock
 * */
int getLine(int sock,char* buf,int size) {
    int i=0;
    char c = '\0';
    while (i+1<size&&c!='\n') {
        int n = recv(sock,&c,1,0);
        if (n > 0) {
            if (c=='\r') { //append \n
                n = recv(sock,&c,1,MSG_PEEK);
                if (n > 0 && c == '\n') {
                    recv(sock,&c,1,0);
                } else {
                    c = '\n';
                }
            }
            buf[i++]=c;
        } else {
            c = '\n';
        }
    }
    buf[i]='\0';
    return i;
}

/**
 * send url to client
 * */
void serveFile(int clientSock,const char* path){
    char buf[BUFFSIZE];
    int numChars = 0;
    do {
        numChars = getLine(clientSock,buf,sizeof(buf));
    } while (numChars>0&&strcmp(buf,"\n")!=0);

    FILE *resource = fopen(path,"r");
    if (resource == NULL) {
        notFound(clientSock);
    } else {
        sendHeader(clientSock,path);
        cat(clientSock,resource);
    }
    fclose(resource);
}

void executeCgi(int clientSock,const char* path,const char* method,const char* queryString) {
    char buf[BUFFSIZE];
    int numChars = 0;
    int content_length = -1;
    if (strcasecmp(method,"GET")==0) {
        do { // read and discard
            numChars = getLine(clientSock,buf,sizeof(buf));
        } while (numChars>0&&strcmp(buf,"\n")!=0);
    } else if (strcasecmp(method,"POST")==0){
        numChars = getLine(clientSock,buf,sizeof(buf));
        while (numChars>0&&strcasecmp("\n",buf)!=0) {
            buf[15]='\0';
            if (strcasecmp(buf,"Content-Length:")==0) {
                content_length = atoi(&buf[16]);
            }
            numChars = getLine(clientSock,buf,sizeof(buf));
        }
        if (content_length==-1) {
            badRequest(clientSock);
            return;
        }
    }

    int cgiOutput[2],cgiInput[2];
    if (pipe(cgiInput)<0) {
        cannotExecute(clientSock);
        return;
    }
    if (pipe(cgiOutput)<0) {
        cannotExecute(clientSock);
        return;
    }

    pid_t pid = fork();
    if (pid<0) {
        cannotExecute(clientSock);
        return;
    }
    sprintf(buf,"HTTP/1.0 200 OK\r\n");
    send(clientSock,buf,strlen(buf),0);
    if (pid==0) { //child
        dup2(cgiOutput[1],1);
        dup2(cgiInput[0],0);
        close(cgiOutput[0]);
        close(cgiInput[1]);

        char methodEnv[ENVSIZE];
        char queryEnv[ENVSIZE];
        char lengthEnv[ENVSIZE];
        sprintf(methodEnv,"REQUEST_METHOD=%s",method);
        putenv(methodEnv);
        if (strcasecmp(method,"GET")==0) {
            sprintf(queryEnv,"QUERY_STRING=%s",queryString);
            putenv(queryEnv);
        } else { //POST
            sprintf(lengthEnv,"CONTENT_LENGTH=%d",content_length);
            putenv(lengthEnv);
        }
        execl(path,path,NULL);
        exit(0);
    } else { // parent
        char ch;
        close(cgiInput[0]);
        close(cgiOutput[1]);
        if (strcasecmp(method,"POST")==0) {
            for (int i = 0; i < content_length; ++i) {
                recv(clientSock,&ch,1,0);
                write(cgiInput[1],&ch,1);
            }
        }
        while (read(cgiOutput[0],&ch,1)>0)
            send(clientSock,&ch,1,0);
        close(cgiOutput[0]);
        close(cgiInput[1]);
        wait(NULL);
    }

}

void sendHeader(int clientSock,const char* path) {
    char buf[BUFFSIZE];
    strcpy(buf,"HTTP/1.0 200 OK\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,SERVERINFO);
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"Content-Type: text/html\r\n");
    send(clientSock,buf,strlen(buf),0);
    strcpy(buf,"\r\n");
    send(clientSock,buf,strlen(buf),0);
}

void cat(int clientSock,FILE* fp) {
    char buf[BUFFSIZE];
    fgets(buf,sizeof(buf),fp);
    while (!feof(fp)) {
        send(clientSock,buf,strlen(buf),0);
        fgets(buf,sizeof(buf),fp);
    }
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
    return httpd;
}

/**
 * create a thread to accept on the port
 * Parameters: the socket connected to the client
 * */
void* acceptRequest(void* arg){
    int clientSock = *(int*)arg;
    char buf[BUFFSIZE];
    size_t numChars = getLine(clientSock,buf,sizeof(buf));

/*    recv(clientSock,buf,1024,0);
    puts(buf);
    return NULL;*/

    int cgi = 0;

    pthread_detach(pthread_self()); // avoid waiting child thread

    //parse request parameters
    char method[METHODSIZE];
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
        cgi = 1;
    }

    char url[URLSIZE];
    i=0;
    while (isspace(buf[j])&&j<numChars) j++;
    while (!isspace(buf[j])&&i+1<sizeof (url)&&j<numChars) {
        url[i] = buf[j];
        i++;j++;
    }
    url[i]='\0';

    char* queryString = NULL;
    if (strcasecmp(method,"GET")==0) {
        queryString = url;
        while (*queryString!='?'&&*queryString!='\0') queryString++;
        if (*queryString=='?') { //cgi program
            cgi =1;
            *queryString = '\0';
            queryString++;
        }
    }

    char path[PAHTSIZE];
    sprintf(path,"/home/chuancey/project/mytinyhttpd/htdocs%s",url); //absolute path ? ? ?
    if (path[strlen(path)-1]=='/') { //directory ?
        strcat(path,"index.html");
    }
//    puts(path); //debug

    struct stat st;
    if (stat(path,&st)==-1) { // file not exists
        while (numChars>0&&strcmp("\n",buf)!=0)
            numChars = getLine(clientSock,buf,sizeof(buf));
        notFound(clientSock);
        fprintf(stderr,"stat:%s,the file path is %s.\n",strerror(errno),path);
    } else {
        if ((st.st_mode&S_IXUSR)||
                (st.st_mode&S_IXGRP)||
                (st.st_mode&S_IXOTH))
            cgi =1;
        if (!cgi) { //normal file
            serveFile(clientSock,path);
        } else { // cgi parse request
//            puts(queryString); //debug
            executeCgi(clientSock,path,method,queryString);
        }
    }
    close(clientSock);
    pthread_exit(NULL);
}


int main(void) {
    u_short port = SERVERPORT;
    int serverSock = startup(&port); //create server socket
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
