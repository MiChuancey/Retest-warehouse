//
// Created by Administrator on 2021/2/6.
//

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static void fun1();
static void fun2();
static void fun3();
static void fun4();

jmp_buf point;

//setjmp 会执行两次

static void fun1() {
    printf("%s is beginning running\n",__FUNCTION__ );
    if (setjmp(point)==0) {
        puts("call fun2");
        fun2();
    } else {
        puts("jmp return");
    }
    setjmp(point);
    printf("%s is ending\n",__FUNCTION__ );
}


static void fun2() {
    printf("%s is beginning running\n",__FUNCTION__ );
    puts("call fun3");
    fun3();
    printf("%s is ending\n",__FUNCTION__ );
}


static void fun3() {
    printf("%s is beginning running\n",__FUNCTION__ );
    puts("call fun4");
    fun4();
    printf("%s is ending\n",__FUNCTION__ );
}


static void fun4() {
    printf("%s is beginning running\n",__FUNCTION__ );
    longjmp(point,666);
    printf("%s is ending\n",__FUNCTION__ );
}

int main(int argc,char** argv) {
    fun1();
    exit(0);
}
