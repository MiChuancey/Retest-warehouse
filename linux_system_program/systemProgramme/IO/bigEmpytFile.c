//
// Created by Administrator on 2021/2/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef NULL
#define NULL 0
#endif

int main(int argc,char* argv[]) {
    if (argc<2) {
        fprintf(stderr,"Usage.....\n");
        exit(1);
    }
    int fd = open(argv[1],O_WRONLY|O_TRUNC|O_CREAT,0600);
    if (fd<0) {
        perror("open():");
        exit(1);
    }

    //产生一个5G大小的文件
    lseek(fd,5LL*1024LL*1024LL*1024LL-1,SEEK_SET);
    write(fd,"",1);

    close(fd);
    exit(0);
}