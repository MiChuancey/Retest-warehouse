//
// Created by Administrator on 2021/2/6.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEFT 1
#define RIGHT 10000

static int isPrime(int x) {
    if (x<2) {
        return 0;
    }
    for (int i = 2; i*i <= x; ++i) {
        if (x%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    for (int i = LEFT; i < RIGHT; ++i) {
        pid_t pid = fork();
        if (pid<0) {
            perror("fork():");
            exit(1);
        } else if (pid == 0) {  // child
            if (isPrime(i)) {
                printf("%d is a prime\n",i);
            }
            exit(0);
        }
    }

    exit(0);
}

