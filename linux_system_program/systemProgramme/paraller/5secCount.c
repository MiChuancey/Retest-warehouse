//
// Created by Administrator on 2021/2/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

int volatile flag = 1;

void func() {
    flag = 0;
}

int main() {

    signal(SIGALRM,func);
    alarm(5);

    unsigned int count = time(0);
    while (flag) {
        count++;
        sleep(1);
    }

    printf("%d\n",count);

    exit(0);
}