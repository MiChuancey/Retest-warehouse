//
// Created by Administrator on 2021/3/12.
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void func(int x){
    write(1,"!",1);
}

int main() {

    signal(SIGINT,func);
    sigset_t sigset,oldSigSet;
    sigemptyset(&sigset);
    sigaddset(&sigset,SIGINT);


    for (int i = 0;  i < 100; ++i) {
//        sigprocmask(SIG_BLOCK,&sigset,NULL);
        sigprocmask(SIG_BLOCK,&sigset,&oldSigSet);
        for (int j = 0; j < 5; ++j) {
            write(1,"*",1);
            sleep(1);
        }
        write(1,"\n",1);
        fflush(stdout);
//        sigprocmask(SIG_UNBLOCK,&sigset,NULL);
        sigprocmask(SIG_SETMASK,&oldSigSet,&sigset);
    }

    return 0;
}