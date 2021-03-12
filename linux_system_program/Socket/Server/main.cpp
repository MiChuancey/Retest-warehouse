#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

    int serSock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    struct sockaddr_in serSockAddr;
 //   memset(&serSockAddr,0,sizeof(serSockAddr));
    serSockAddr.sin_family = AF_INET;
    serSockAddr.sin_port = htons(50002);
    serSockAddr.sin_addr.s_addr =  INADDR_ANY;

    bind(serSock,(struct sockaddr*)&serSockAddr,sizeof (serSockAddr));
    listen(serSock,10);

    while (1) {
        struct sockaddr_in clientAddr; //客户端的地址
        socklen_t  socklen = sizeof (clientAddr);
        int connection = accept(serSock,(struct sockaddr*)&clientAddr,&socklen);

        puts("dssdsdfsdf00");
        char str[]="12345";
        write(connection,str,sizeof (str));

        close(connection);
    }


    close(serSock);

    return 0;
}
