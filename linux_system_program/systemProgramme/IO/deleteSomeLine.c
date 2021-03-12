//
// Created by Administrator on 2021/1/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef NULL
#define NULL 0
#endif

#define BUFSIZE 1024

int main(int argc,char* argv[]) {
    if (argc < 2) {
        fprintf(stderr,"Usage....\n delete tenth line character");
        exit(1);
    }
    FILE *preF = fopen(argv[1],"rw");
    if (preF==NULL) {
        perror("fopen():");
        exit(1);
    }
    fseek(preF,0,SEEK_SET);

    FILE *tmp = tmpfile();
    fseek(tmp,0,SEEK_SET);

    char buf[BUFSIZE];
    for (int i = 0; i < 10; ++i) {
        fgets(buf,BUFSIZE,preF);
        fputs(buf,tmp);
    }
    fgets(buf,BUFSIZE,preF);

    while (fgets(buf,BUFSIZE,preF)!=NULL) {
        fputs(buf,tmp);
    }

    fseek(tmp,0,SEEK_SET);
    while (fgets(buf,BUFSIZE,tmp)!=NULL) {
        fputs(buf,preF);
    }
    fclose(tmp);
    fclose(preF);

    return 0;
}
