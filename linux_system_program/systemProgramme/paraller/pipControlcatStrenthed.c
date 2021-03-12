//
// Created by Administrator on 2021/2/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define BUFFSZ 10


// 应对流量变化
static int token=0;
static void sig_handler(int s) {
    alarm(1);
    token++;
}

int main(int argc,char** argv) {
    if (argc < 2) {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }

    int fd = open(argv[1],O_RDONLY,0600);
    if (fd<0) {
        perror("open():");
        exit(1);
    }

    signal(SIGALRM,sig_handler);
    alarm(1);

    char buf[BUFFSZ];
    while (1) {
        while (token<=0) pause();
        token--;

        int ret = read(fd,buf,BUFFSZ);
        while (ret == -1) { // while 持续判断是否有信号打断
            if (errno == EINTR) continue; //被signal打断
            perror("open():");
            exit(1);
        }
        if (ret==0) break;
        int wtd=0,wlen=BUFFSZ,pos =0;
        while (wtd = write(1,buf+pos,wlen) <BUFFSZ) {
            if (wtd < 0) {
                if (errno==EINTR) continue;
                perror("write():");
                exit(1);
            }
            wlen -= wtd;
            pos += wtd;
        }

    }
    puts("");
    close(fd);
    exit(0);
}
