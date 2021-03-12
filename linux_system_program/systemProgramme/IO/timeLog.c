//
// Created by Administrator on 2021/2/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define PATH "/tmp/logFile"
#define BUFSIZE 1024

#ifndef NULL
#define NULL 0
#endif

int main(int argc,char** argv) {
    FILE *fp = fopen(PATH,"a+");
    if (fp==NULL) {
        perror("fopen():");
        exit(1);
    }

    int getLines = 1;
    char buffer[BUFSIZE];
    while (fgets(buffer,BUFSIZE,fp)!=NULL) getLines++;

    while (1) {
        time_t sourceTime = time(NULL);
        struct tm* localTime = localtime(&sourceTime);
        fprintf(fp,"%d %d-%d-%d %d:%d:%d\n",
                getLines++,localTime->tm_year+1900,localTime->tm_mon+1,localTime->tm_mday,
                localTime->tm_hour,localTime->tm_min,localTime->tm_sec);
        fflush(fp);
        sleep(1);

    }


    exit(0);
}

