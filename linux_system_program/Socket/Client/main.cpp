#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

int main() {
    int clientSocket = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serSockAddr;
 //   memset(&serSockAddr,0,sizeof(serSockAddr));
    serSockAddr.sin_family = AF_INET;
    serSockAddr.sin_port = htons(50002);
    serSockAddr.sin_addr.s_addr =  INADDR_ANY;

    connect(clientSocket,(struct sockaddr*)&serSockAddr,sizeof (serSockAddr));

    char buffer[4444];
    read(clientSocket,buffer,sizeof(buffer)-1);

    puts(buffer);

    close(clientSocket);

    return 0;
}
