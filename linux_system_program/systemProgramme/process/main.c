#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef NULL
#define NULL 0
#endif

int main() {

    printf("[%d]: begins\n",getpid());

    fflush(NULL);

    pid_t pid = fork();
    if (pid<0) {
        perror("fork()");
        exit(1);
    } else if (pid==0){ // child
        printf("[%d]: is running\n",getpid());

    } else {
        printf("[%d]: is running\n",getpid());
    }
    printf("[%d]: ends\n",getpid());
    return 0;
}
