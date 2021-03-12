//
// Created by Administrator on 2021/2/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>


#ifndef NULL
#define NULL 0
#endif

#define PATH "/etc/"


int main() {
    DIR *dir = opendir(PATH);
    if (dir==NULL) {
        perror("opendir():");
        exit(1);
    }
    struct dirent* res;
    while ((res=readdir(dir))!=NULL) {
        puts(res->d_name);
    }
    closedir(dir);
    exit(0);
}