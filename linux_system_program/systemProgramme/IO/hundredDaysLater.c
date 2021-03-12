//
// Created by Administrator on 2021/2/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef NULL
#define NULL 0
#endif

#define BUFFSIZE 1024

int main() {

    time_t sourceTime = time(NULL);
    struct tm* localTime = localtime(&sourceTime);
    char buffer[BUFSIZ];
    strftime(buffer,BUFSIZ,"current time: %Y-%m-%d\n",localTime);
    puts(buffer);

    localTime->tm_mday+=100;
    mktime(localTime);
    strftime(buffer,BUFSIZ,"100 days later time: %Y-%m-%d\n",localTime);
    puts(buffer);
    exit(0);
}