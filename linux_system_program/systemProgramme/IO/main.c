#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define NULL 0

int main() {
    FILE *p = fopen("test","r");
    if (p==NULL) {
        perror("fopen():");
        fprintf(stderr,"fopen():%s",strerror(errno));
        exit(1);
    }
    puts("文件打开成功");
    fclose(p);
    return 0;
}
