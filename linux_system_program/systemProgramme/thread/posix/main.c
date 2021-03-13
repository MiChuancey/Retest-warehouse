#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* hello (void* arg){
    puts("thread is woking");
}

int main() {
    printf("Hello, World!\n");

    pthread_t tid;
    int retNum = pthread_create(&tid,NULL,hello,NULL);
    if(retNum!=0) {
        fprintf(stderr,"pthread_create %s\n",strerror(retNum));
        exit(1);
    }
    puts("over");
    return 0;
}
