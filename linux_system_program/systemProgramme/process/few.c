//
// Created by Administrator on 2021/2/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#ifndef NULL
#define NULL 0
#endif

int main() {
    puts("begin");

    fflush(NULL);
    pid_t pid = fork();
    if (pid<0) {
        perror("fork()");
        exit(1);
    } else if (pid==0) { //子进程
        execl("/usr/bin/date","date","+%s",NULL);
        exit(0);
    }
    wait(NULL);


    puts("end");

    exit(0);
}