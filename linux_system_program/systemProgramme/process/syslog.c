//
// Created by Administrator on 2021/2/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define PATH "/tmp/out"

static int daemonize() {
    fflush(0);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork():");
        return -1;
    } else if (pid > 0) {
        exit(0);
    } else {
        // 后台进程脱离终端，将标准输入输出设备取消绑定
        int fd = open("/dev/null",O_RDWR);
        dup2(fd,0);
        dup2(fd,1);
        dup2(fd,2);
        if (fd > 2) close(fd);

        pid_t res = setsid();
        if (res<0) {
            perror("setsid():");
            return -1;
        }

        chdir("/"); //切换工作目录，防止当前目录被删除，程序被强制退出
        return 0;
    }
}

int main() {
    if (daemonize()) {
        fprintf(stderr, "encounter errors\n");
        exit(1);
    }


    FILE *fp = fopen(PATH,"w");
    if (fp==0) {
        perror("fopen()");
        exit(1);
    }
    int count=0;
    while (1) {
        fprintf(fp,"%d\n",count++);
        fflush(fp);         // 一定要记得刷新流
        sleep(1);
    }

    exit(0);
}

