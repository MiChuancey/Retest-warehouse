//
// Created by Administrator on 2021/1/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NULL
#define NULL 0
#endif

int main(int argc,char* argv[]) {
    if (argc<2) {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }
    FILE* p = fopen(argv[1],"r");
    if (p==NULL) {
        perror("fopen():");
        exit(1);
    }

    char *buf=NULL;
    ssize_t num = 0;

    while (1) {
        if (getline(&buf,&num,p)<0) break;
        fprintf(stdout,"%zd\n",num);
    }
    free(buf);
    fclose(p);
    exit(0);
}