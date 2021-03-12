//
// Created by Administrator on 2021/2/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#ifndef NULL
#define NULL 0
#endif

#define BUFFSIZE 1024
#define STRFSIZE 1024

int main(int argc,char* argv[]) {

    if (argc < 2) {
        fprintf(stderr,"Usge...\n");
        exit(1);
    }

    int opt;
    char strfstr[STRFSIZE]="\0";
    while ((opt=getopt(argc,argv,"y:mdh:Ms"))!=-1) {
        switch (opt) {
            case 'y':
                if (strcmp(optarg,"4")==0) {
                    strcat(strfstr,"%Y ");
                } else if (strcmp(optarg,"2")==0) {
                    strcat(strfstr,"%y ");
                } else {
                    fprintf(stderr,"arg error\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 'm':
                strcat(strfstr,"%m ");
                break;
            case 'd':
                strcat(strfstr,"%d");
                break;
            case 'h':
                if (strcmp(optarg,"24")==0) {
                    strcat(strfstr,"%H ");
                } else if (strcmp(optarg,"12")==0) {
                    strcat(strfstr,"%I ");
                } else {
                    fprintf(stderr,"arg error\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 'M':
                strcat(strfstr,"%M ");
                break;
            case 's':
                strcat(strfstr,"%s ");
                break;
            default:
                fprintf(stderr,"Usage...\n");
                exit(EXIT_FAILURE);
        }
    }

    time_t sourceTime = time(NULL);
    struct tm* localTime = localtime(&sourceTime);
    char buffer[BUFSIZ];
    strftime(buffer,BUFSIZ,strfstr,localTime);
    puts(buffer);


    exit(0);
}