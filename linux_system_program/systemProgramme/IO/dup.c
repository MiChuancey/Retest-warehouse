//
// Created by Administrator on 2021/1/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PATH "/tmp/out"

int main() {

    int fd = open(PATH,O_WRONLY|O_CREAT|O_TRUNC,0600);
    if (fd<0) {
        perror("open()");
        exit(1);
    }

    int ret = dup2(fd,1);
    if (ret!=1) close(fd);

    /**********************************************************/

    puts("Hello World!\n");
    exit(0);
}

