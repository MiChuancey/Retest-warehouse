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

    sigprocmask(SIG_BLOCK,&sigset,&oldSigSet);
    for (int i = 0;  i < 100; ++i) {

        for (int j = 0; j < 5; ++j) {
            write(1,"*",1);
            sleep(1);
        }
        write(1,"\n",1);
        fflush(stdout);
        sigsuspend(&oldSigSet); //作用相当于下面的三行，先恢复到未阻塞的状态，再等待信号驱动程序
//        sigprocmask(SIG_SETMASK,&oldSigSet,&sigset);
//        pause();
//        sigprocmask(SIG_BLOCK,&sigset,&oldSigSet);
    }
    sigprocmask(SIG_UNBLOCK,&sigset,NULL);

    return 0;
}