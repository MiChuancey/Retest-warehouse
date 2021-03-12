//
// Created by Administrator on 2021/2/5.
//

#include <stdio.h>
#include <stdlib.h>

void fun1() {
    puts("fun1 is running");
}

void fun2() {
    puts("fun2 is running");
}

void fun3() {
    puts("fun3 is running");
}

int main() {
    puts("main begins running");

    atexit(fun1);
    atexit(fun2);
    atexit(fun3);

    puts("main is stopping");
    return 0;
}