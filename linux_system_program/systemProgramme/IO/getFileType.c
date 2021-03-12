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

static char getType(const char* fileName) {
    struct stat fileStat;
    if(stat(fileName,&fileStat)<0) {
        perror("stat():");
        exit(1);
    }

    // 详情 man 7 inode 找st_mode位图
    if ((fileStat.st_mode & S_IFMT)==S_IFREG) {
        return '-';
    }
    if ((fileStat.st_mode & S_IFMT)==S_IFDIR) {
        return 'e';
    }

}

int main(int argc,char* argv[]) {
    if (argc<2) {
        fprintf(stderr,"Usage.....\n");
        exit(1);
    }
    printf("FileType:%c\n",getType(argv[1]));


    exit(1);
}