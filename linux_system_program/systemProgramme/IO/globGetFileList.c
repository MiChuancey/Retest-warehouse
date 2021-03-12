//
// Created by Administrator on 2021/2/4.
//


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <glob.h>

#ifndef NULL
#define NULL 0
#endif

#define PATH "/etc/*"

int main (int argc, char** argv) {

//    if (argc < 2) {
//        fprintf(stderr,"Usage....\n");
//        exit(1);
//    }

    glob_t globRes;   //用来存放被解析的目录

    if(glob(PATH,0,NULL,&globRes)==0) {
        for (int i = 0; i < globRes.gl_pathc; ++i) {
            puts(globRes.gl_pathv[i]);
        }
    } else {
        fprintf(stderr,"glob error！\n");
        exit(1);
    }

    // 错误写法，shell无法传入*和？通配符，如果写*，在传参之前会被转换成具体的名称
//    if(glob(argv[1],0,NULL,&globRes)==0) {
//        for (int i = 0; i < globRes.gl_pathc; ++i) {
//            puts(globRes.gl_pathv[i]);
//        }
//    } else {
//        fprintf(stderr,"glob error！\n");
//        exit(1);
//    }

    // 记得销毁glob_t结构体
    globfree(&globRes);
    exit(0);
}
