
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFSIZE 1024

int main(int argc,char* argv[]) {
    if (argc<3) {
        fprintf(stderr,"Usage....\n");
        exit(1);
    }

    int sfd = open(argv[1],O_RDONLY);
    if (sfd<0) {
        perror("sfdOpen():");
        exit(1);
    }
    int dfd = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0600); //不加0600操作完只有写权限
    if (dfd<0) {
        close(sfd);
        perror("dfdOpen():");
        exit(1);
    }

    char buf[BUFFSIZE];
    while (1) {

        int count=read(sfd,buf,BUFFSIZE);
        if (count<0) {
            perror("read():");
            break;
        }
        if (count==0) break;
        int writeNum = write(dfd,buf,count);
        fprintf(stdout,"size:%d\t writeNUm:%d\n",count,writeNum);
    }

    close(dfd);
    close(sfd);
    return 0;
}
