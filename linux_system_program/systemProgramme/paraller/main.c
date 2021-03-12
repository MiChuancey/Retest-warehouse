#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void func(int x){}

int main() {

//    signal(SIGINT,SIG_DFL); //SIG_DFL—采用系统默认处理

    signal(SIGINT,func);

    for (int i = 0; i < 100; ++i) {
        putchar('*');
        sleep(1);
        fflush(stdout);
    }

    return 0;
}
