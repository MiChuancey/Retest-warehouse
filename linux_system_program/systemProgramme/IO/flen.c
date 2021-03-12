//
// Created by Administrator on 2021/2/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef NULL
#define NULL 0
#endif

static off_t getFileLen(const char* fileName) {
    struct stat res;
    if (stat(fileName,&res)==-1) {
        perror("stat():");
        exit(1);
    }
    return res.st_size;
}

int main(int argc,char* argv[]) {
    if (argc<2) {
        fprintf(stderr,"Usage.....\n");
        exit(1);
    }

    printf("%ld\n",getFileLen(argv[1]));
    exit(0);
}
