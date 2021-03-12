//
// Created by Administrator on 2021/1/18.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef NULL
#define NULL 0
#endif

int main(int argc, char* argv[]) {
    if (argc<3) {
        fprintf(stderr,"Usage...srcFile destFile\n");
        exit(1);
    }

    FILE *srcFile=fopen(argv[1],"r");
    if (srcFile==NULL) {
        perror("fopen():srcfile");
        exit(1);
    }

    FILE *dstFile=fopen(argv[2],"w");
    int count = 0;
    while (1) {
        int ch = fgetc(srcFile);
        if (ch==EOF) break;
        fputc(ch,dstFile);
        count++;
    }
    fprintf(stdout,"%s has been copied,and the file size is %dByte\n",argv[1],count);
    fclose(dstFile);
    fclose(srcFile);
    return 0;

}
