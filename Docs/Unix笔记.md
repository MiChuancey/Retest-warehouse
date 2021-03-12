# APUE

## 系统基础知识

### shell

- unix：shell
- Linux：bash

> 清屏快捷键：CTRL+Ｌ

### 常见命令

```shell
cd - 					   # 切换到上次的目录
ls -R					   # 递归的显示目录
cp -a					   # 拷贝全部信息
ln -s file fileSoftlink		# 创建软链接
ln file fileLink		    # 创建硬链接

# find命令的使用
# 参数
-type -name -maxdepth -size
# 举例
find /usr/ -name "*tmp*"

# root环境下创建新用户，配置密码，并赋予sudoer权限
# 添加用户 adduser chuancey
# 配置密码 passwd chuancey
# 赋予sudoer权限 vim /etc/sudoers 在root ALL下面一行添加
```

### 文件类型

1. 普通文件
2. 目录文件
3. 字符设备
4. 块设备
5. 软链接
6. 管道文件
7. 套接字文件

### Vim的使用

- 跳转行： 行号+G
- 大括号对应跳转：%
- 单个删除：x
- 多选删除：v模式下选中块+d
- 复制粘贴：
  - 两下yy复制
  - p：粘贴到光标的下一行
  - P：粘贴到光标的上一行
- 查找：/pattern
- 跳转到下一个相同的单词：*
- 查询man：在函数身上shift+k,自动跳转到man手册

### GCC编译参数

```bash
-I		#指定头文件所在目录
-c 		#得到汇编程序.o文件
-g		#编译时添加调试语句，用于GDB
-Wall	#显示所有警告信息，有行号的错误信息在编译阶段，否则是链接阶段
-D		#编译阶段注册一个宏
```



### 静态库

- 制作

  ```bash
  ar rcs libName file1.o file2.o
  ```

- 使用：直接把静态库与使用到静态库的源文件放在一起编译即可

  ```bash
  gcc sourcefile.c libName1.a libName2.a -o a.out
  ```

  > 注：制作的静态库需要有头文件

### 动态库

- 制作（生成与内存位置无关的代码）

  ```bash
  gcc -shared -fPIC -c hello.c 
  gcc -shared -fPIC -o libmyhello.so hello.o
  ```

- 使用

  ```bash
  # 需要讲制作的动态库复制到库目录，如/usr/lib
  # 可指定文件，指定目录 -l 库名 -L 库路径
  gcc main.c -o main libmyhello.so
  ```

> 使用命令：`ldd a.out`可查看当前文件需要加载的动态库

### Makefile/makefile

> 1个规则 两个函数 三个自动变量
>
> 
>
> **规则**：
>
> - 若想生成目标，检查规则中的依赖条件是否存在，不存在则寻找是否有规则来生成依赖文件
> - 检查规则中的目标是否更新，必须先检查它所有的依赖，依赖中有一个被更新，则目标必须更新
>
> ALL:指定最终目标文件
>
> 
>
> **函数**：
>
> ```bash
> $(wildcard ./*.c) 				# 匹配当前目录下的所有.c文件
> $(patsubst %.c,%.o,$(src))		 # 把src变量里所有后缀为.c的文件替换成.o
> 
> clean:
> 	-rm -rf ...... 				# 清理
>     
> make clean -n 					# 尝试删除
> ```
>
> 
>
> **自动变量**（只能用在命令中）
>
> $@: 在规则的命令中，表示目标。
>
> $<: 表示规则中的第一个条件
>
> $^: 表示规则中的所有条件，组成一个列表，以空格分开，不存在重复项
>
> 
>
> **模式规则**
>
> %.o:%.c		表示模式模式匹配，静态模式匹配中`$(obj): %.o:%.c` 表示obj中所有的%.o都依赖于%.c
>
> `gcc -c $< -o $@`	中，$<所代表的依赖文件会随着生成目标的不同依次发生改变
>
> 
>
> **参数**
>
> -n 查看预执行的命令
>
> -f 指定makefile文件
>
> **伪目标**
>
> `.PHONY: clean,ALL`

### man手册

第七章讲机制



## 系统编程

### IO 

> 有两种IO，系统IO和标准IO；当两种都可用的时候，优先使用标准IO
>
> 标准IO对系统IO进行整合，有缓冲加速机制。

#### 标准IO 

> FILE类型贯穿始终

```c
fopen();
fclose();

fgetc();
fputc();
fputs();
fread(); //为防止遗漏,对文件操作要一个字节一个字节操作   ---->fseeko
fwrite();

fseek(); //有long,文件有限制2G ,可配合ftell测出文件大小;可产生空洞文件
ftell();
rewind();

fflush(); //强制刷新缓冲区. printf为行缓冲,无特殊要求要加换行符
/*
	缓冲区的作用:合并系统调用
	
	- 行缓冲: 换行时候刷新,满的时候刷新,强制刷新 (标准输出是这样)
	
	- 全缓冲: 满了的时候刷新,强制刷新(除了终端设备,其他默认为全缓冲)
	
	- 无缓冲: 如stderr,需要立即输出的内容
*/
```

- getline 完整的获得一行

  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  
  int main(int argc,char* argv[]) {
      if (argc<2) {
          fprintf(stderr,"Usage...\n");
          exit(1);
      }
      FILE* p = fopen(argv[1],"r");
      if (p==NULL) {
          perror("fopen():");
          exit(1);
      }
  
      char *buf=NULL;	//初始化!!!!!!!!!!!!!
      ssize_t num = 0;	//初始化!!!!!!!!!!!!!
  
      while (1) {
          if (getline(&buf,&num,p)<0) break;
          fprintf(stdout,"%zd\n",num);
      }
      free(buf);	//释放堆区!!!!
      fclose(p);	//关闭流!!!!!
      exit(0);
  }
  ```

  

- 临时文件

  ```c
  #include <stdio.h>
  char *tmpnam(char *s); 	//不可并发,并发时不安全
  FILE *tmpfile(void);    //解决了冲突问题,可以及时销毁
  ```

  

#### 文件IO/系统调用IO

> fd是在文件IO中贯穿始终的类型
>
> 文件描述符就是一个整型数
>
> 文件描述符优先使用当前可用范围内最小的

 - 文件IO操作

   ```c
   open();
   close();
   read();
   write();
   lseek();
   ```

- 文件IO与标准IO的区别

  - 响应速度:系统调用的实时性更高,不需要等缓冲区满再进行操作

  - 吞吐量:标准IO更大

  - 标准IO和系统IO不可混用

  - 两者的相互转换,即使可以转换,也不要混用

    ```c
    //标准IO转换成系统IO操作
    FILE *fdopen(int fd, const char *mode);
    //系统IO转换成标准IO操作
    int fileno(FILE *stream);
    ```

    

- 文件共享

  > 面试题:写程序,删除文件的第十行-----------待完成

- 原子操作:解决竞争和冲突

  

- 重定向:dup,dup2

  ```c
   int fd = open(PATH,O_WRONLY|O_CREAT|O_TRUNC,0600);
      if (fd<0) {
          perror("open()");
          exit(1);
      }
  
      int ret = dup2(fd,1);
      if (ret!=1) close(fd);
  
      /**********************************************************/
  
      puts("Hello World!\n");
  ```

- 同步:sync,fsync,fdatasync

  

- fcntl和ioctl

  > fcntl:文件描述符的管家级函数
  >
  > ioctl:设备相关的内容

- /dev/fd/ 的目录

  > 这是一个虚目录;显示的是当前进程的文件描述符信息





### 文件系统

#### 文件

- 获取文件属性

  ```c
  int stat(const char *pathname, struct stat *statbuf);
  int fstat(int fd, struct stat *statbuf);
  int lstat(const char *pathname, struct stat *statbuf);
  
  
  //关键的结构体
  struct stat {
                 dev_t     st_dev;         /* ID of device containing file */
                 ino_t     st_ino;         /* Inode number */
                 mode_t    st_mode;        /* File type and mode */
                 nlink_t   st_nlink;       /* Number of hard links */
                 uid_t     st_uid;         /* User ID of owner */
                 gid_t     st_gid;         /* Group ID of owner */
                 dev_t     st_rdev;        /* Device ID (if special file) */
                 off_t     st_size;        /* Total size, in bytes */
                 blksize_t st_blksize;     /* Block size for filesystem I/O */
                 blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */
  
                 /* Since Linux 2.6, the kernel supports nanosecond
                    precision for the following timestamp fields.
                    For the details before Linux 2.6, see NOTES. */
  
                 struct timespec st_atim;  /* Time of last access */
                 struct timespec st_mtim;  /* Time of last modification */
                 struct timespec st_ctim;  /* Time of last status change */
  
             #define st_atime st_atim.tv_sec      /* Backward compatibility */
             #define st_mtime st_mtim.tv_sec
             #define st_ctime st_ctim.tv_sec
             };
  
  //真正的文件大小=blokcs数*blocksize值，Linux环境下size值只是一个属性值，跟实际占用磁盘大小无关
  ```

  > stat: 通过文件路径获取属性，面对符号链接文件时获取的是所指文件的属性
  >
  > fstat：通过文件描述符获取属性
  >
  > lstat：面对符号链接文件时获取的是符号链接文件的属性

- 文件访问权限

  stat结构体中的st_mode是一个16位的位图，用于表示文件类型，文件访问权限，及特殊权限位

- umask

  权限值为 0666 & ~umask

  可以调用umask函数设置文件的权限；

  作用就是：防止产生权限过松的文件

- 文件权限的更改/管理

  ```c
   #include <sys/stat.h>
  
  int chmod(const char *pathname, mode_t mode);
  int fchmod(int fd, mode_t mode);
  ```

  

- 粘住位(T位)

  在内存中留下使用痕迹，使下次使用时加载更快。如tmp目录有粘住位t

- 文件系统：FAT，UFS

- 硬链接，符号链接

  > 硬链接不能给分区和目录建立
  >
  > 符号链接可以跨分区，可以给目录建立

  ```c
  #include <unistd.h>
  // 建立硬链接
  int link(const char *oldpath, const char *newpath);
  
  //删除链接，符号链接直接删除
  int unlink(const char *pathname);
  
  // 此函数也可用于创建临时匿名文件，首先创建一个文件，open打开，然后unlink，此时open仍可以使用这个文件，试用结束后才会被删除
  ```

- utime

  用来更改一个文件的时间：atime和mtime

- 目录的创建和销毁

  ```c
  #include <sys/stat.h>
  #include <sys/types.h>
  
  int mkdir(const char *pathname, mode_t mode);
  int rmdir(const char *pathname);
  ```

- 更改当前路径

  ```c
  #include <unistd.h>
  
  int chdir(const char *path);
  int fchdir(int fd);
  
  char *getcwd(char *buf, size_t size); //获取当前工作路径
  ```



#### 目录

```c
int glob(const char *pattern, int flags,
                int (*errfunc) (const char *epath, int eerrno),
                glob_t *pglob);   // 可以用来解析目录


opendir();
closedir();
readdir();
rewinddir();
seekdir();
telldir();
```



#### 系统数据文件和信息

- /etc/passwd		用于用户信息查询

  ```c
  #include <sys/types.h>
  #include <pwd.h>
  
  struct passwd *getpwnam(const char *name);
  
  struct passwd *getpwuid(uid_t uid);
  
  
  struct passwd {
      char   *pw_name;       /* username */
      char   *pw_passwd;     /* user password */
      uid_t   pw_uid;        /* user ID */
      gid_t   pw_gid;        /* group ID */
      char   *pw_gecos;      /* user information */
      char   *pw_dir;        /* home directory */
      char   *pw_shell;      /* shell program */
  };
  
  ```

- /etc/group        查询组的相关信息

  ```c
  #include <sys/types.h>
  #include <grp.h>
  
  struct group *getgrnam(const char *name);
  
  struct group *getgrgid(gid_t gid);
  
  
  struct group {
      char   *gr_name;        /* group name */
      char   *gr_passwd;      /* group password */
      gid_t   gr_gid;         /* group ID */
      char  **gr_mem;         /* NULL-terminated array of pointers
                                            to names of group members */
  };
  
  
  ```

- /etc/shadow

  加密相关；

  哈希是混淆，不可逆，不能称为加密

  加密的实现：

  ```c
  /* General shadow password file API */
  #include <shadow.h>
  
  struct spwd *getspnam(const char *name);
  
  
  
  #include <crypt.h>
  
  char *crypt(const char *phrase, const char *setting);
  
  
  #include <unistd.h>
  
  char *getpass(const char *prompt);
  
  ```

- 时间戳

  ```C
  #include <time.h>
  
  time_t time(time_t *tloc);
  
  #include <time.h>
  struct tm *gmtime(const time_t *timep);
  struct tm *localtime(const time_t *timep);
  time_t mktime(struct tm *tm);				//此函数会先判断tm是否合法，不合法的时间要先调整到合法的时间；用于求100天后是第几天
  
  size_t strftime(char *s, size_t max, const char *format,
                         const struct tm *tm);
  
  ```

  

#### 进程环境(单进程)

- 进程的终止

  - 正常终止

    - 从main函数return
    - 调用exit
    - 调用 _exit 或 _Exit
    - 最后一个线程从其启动例程返回
    - 最后一个线程调用pthread_exit

    > exit()函数在调用exit 系统调用前要检查文件的打开情况，把文件缓冲区中的内容写回文件,可以在调用后执行钩子函数
    >
    > _exit 函数的作用是：直接使进程停止运行，清除其使用的内存空间，并清除其在内核的各种数据结构；

  - 异常终止

    - 调用abort
    - 接到一个信号并终止
    - 最后一个线程对其取消请求做出相应

  ```c
  // 钩子函数-----------------------> 防止内存泄露，依次释放资源
  // register a function to be called at normal process termination
  #include <stdlib.h>
  
  int atexit(void (*function)(void));
  ```

- 命令行参数的分析

  ```c
  // getopt();
  #include <unistd.h>
  
  int getopt(int argc, char * const argv[],
             const char *optstring);
  
  
  extern char *optarg;
  extern int optind, opterr, optopt;
  
  // getopt_long();
  #include <getopt.h>
  
  int getopt_long(int argc, char * const argv[],
                  const char *optstring,
                  const struct option *longopts, int *longindex);
  
  
  ```

- 环境变量

  > 用export命令查看环境变量；实际程序中，可以使用全局变量`extern char **environ;`指向环境变量中的所有内容

  ```c
  extern char **environ;
  
  char *getenv(const char *name);
  int setenv(const char *name, const char *value, int overwrite);
  int putenv(char *string);			// 不好用，没有const修饰，能不用则不用
  ```

- 库

  > - 动态库
  > - 静态库
  > - 手工装载库

- 函数跳转（安全跳转）

  ```c
  #include <setjmp.h>
  
  int setjmp(jmp_buf env); //jmp会执行两次，第一次返回值为0，第二次从longjmp跳转时，返回值为longjmp的val值
  void longjmp(jmp_buf env, int val); 
  ```

- 资源获取和控制

  ```c
  #include <sys/time.h>
  #include <sys/resource.h>
  
  int getrlimit(int resource, struct rlimit *rlim);
  int setrlimit(int resource, const struct rlimit *rlim);
  
  
  // 这两个函数就可以构造出ulimit命令
  ```



### 进程

#### 进程标识符pid

类型pid_t

ps命令常用组合

```bash
ps axf
ps axm
ps ax -L
```

进程号是顺次向下使用

```c
#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);
pid_t getppid(void);
```



#### 进程的产生

```c
#include <sys/types.h>
#include <unistd.h>

pid_t fork(void);

// 使用fork前一定要刷新所有打开的流fflush(NULL);
```

> fork后父子进程的区别：
>
> - fork的返回值不一样
> - pid不同
> - ppid不同
> - 未决信号和文件锁不继承
> - 资源利用率清零
>
> 调度器的调度策略决定父子进程哪个进程先运行

init进程：是所有进程的祖先进程

####  进程的消亡及释放资源

```c
#include <sys/wait.h>

pid_t wait(int *stat_loc);
pid_t waitpid(pid_t pid, int *stat_loc, int options);

int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);

#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

pid_t wait3(int *wstatus, int options,
            struct rusage *rusage);

pid_t wait4(pid_t pid, int *wstatus, int options,
            struct rusage *rusage);

```



#### exec函数族

```c
#include <unistd.h>

extern char **environ;

int execl(const char *path, const char *arg, ...
          /* (char  *) NULL */);
int execlp(const char *file, const char *arg, ...
           /* (char  *) NULL */);
int execle(const char *path, const char *arg, ...
           /*, (char *) NULL, char * const envp[] */);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[],
            char *const envp[]);


// exec使用前也一定要fflush
```

> fork+exec+wait来实现一个命令，整个unix世界均是如此

#### 用户权限和组权限

> 用ls -l命令可以看到文件的权限信息，格式如：-rwxr-xr-x
>
> 这种表示方法一共是十位：
>
> 9 8 7 6 5 4 3 2 1 0 
> \-  r  w x r  -  x r  - x
>
> 第9位表示文件类型,可以为p、d、l、s、c、b和-：
>
> p表示命名管道文件 
> d表示目录文件 
> l表示符号连接文件 
> -表示普通文件 
> s表示socket文件 
> c表示字符设备文件 
> b表示块设备文件
>
> 第8-6位、5-3位、2-0位分别表示文件所有者的权限，同组用户的权限，其他用户的权限，其形式为rwx：
>
> r表示可读，可以读出文件的内容
>
> w表示可写，可以修改文件的内容
>
> x表示可执行，可运行这个程序
>
> 没有权限的位置用-表示
>
> ----
>
> real 、effective  [讲解](https://www.cnblogs.com/findstr/archive/2012/03/07/2803697.html)
>
> 鉴定权限使用effective
>
> ```bash
> [chuancey@AliUbuntu ~]$ ls -l /usr/bin/passwd 
> -rwsr-xr-x. 1 root root 33600 Apr  7  2020 /usr/bin/passwd
> ```
>
> 

```c
#include <unistd.h>
#include <sys/types.h>

uid_t getuid(void);
uid_t geteuid(void);

gid_t getgid(void);
gid_t getegid(void);

int setuid(uid_t uid);
int setgid(gid_t gid);

int setreuid(uid_t ruid, uid_t euid);
int setregid(gid_t rgid, gid_t egid);

int seteuid(uid_t euid);
int setegid(gid_t egid);
```



#### system函数

```c
#include <stdlib.h>

int system(const char *command);

```

fork+exec+wait的封装



#### 进程时间

```c
#include <sys/times.h>

clock_t times(struct tms *buffer);
```

用于实现time命令



#### 守护进程

会话 session，标识：sid

终端 ：只有输入输出功能

前台进程组和后台进程组：前台进程最多只能有一个

守护进程的单实例化：锁文件 /var/run/xxx.pid

启动脚本文件

```c
#include <unistd.h>
// 使用命令 ps axj 查看进程，tty字段为？的就是后台进程
pid_t setsid(void);	//实现一个守护进程

```

#### 系统日志

> 系统日志所在目录：/var/log
>
> 主日志文件：/var/log/messages
>
> 通过请求syslogd服务，提交系统日志

```c
#include <syslog.h>

void openlog(const char *ident, int option, int facility);
void syslog(int priority, const char *format, ...);
void closelog(void);

```

### 进程通信

> Linux下的进程通信方式
>
> - pipe管道
> - fifo管道
> - 内存共享映射
> - unix domain socket

### 并发

> 信号实现和线程实现不要混用

#### 信号实现

- 信号的概念

  软件中断

  信号的相应依赖于中断

- signal

  使用命令`kill -l`可以看到信号；有标准信号和实时信号(real)

  ```bash
  1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
   6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
  11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
  16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
  21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
  26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
  31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) SIGRTMIN+3
  38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) SIGRTMIN+8
  43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) SIGRTMIN+12	47) SIGRTMIN+13
  48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) SIGRTMAX-13	52) SIGRTMAX-12
  53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) SIGRTMAX-8	57) SIGRTMAX-7
  58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) SIGRTMAX-2
  63) SIGRTMAX-1	64) SIGRTMAX	
  
  ```

  

  ```c
  #include <signal.h>
  
  typedef void (*sighandler_t)(int);
  
  sighandler_t signal(int signum, sighandler_t handler);
  // 将typedef展开后：
  void (*signal(int signum,void (*func)(int))) (int)
  // signum由kill -l命令查阅
  ```

  **信号会打断阻塞的系统调用**

  

- 信号的不可靠

  并非指信号会丢失，而是处理信号的行为不可靠

- 可重入函数：所有的系统调用都是可重入的，一部分库函数也是可重入的

- 信号的响应过程（mask和pending的按位与操作）

  信号从收到到响应有一个不可避免的延迟

  标准信号的相应没有严格的顺序

  不能从信号处理函数中随意的往外跳（siglongjmp）

- 常用函数

  ```c
  #include <sys/types.h>
  #include <signal.h>
  #include <unistd.h>
  
  int kill(pid_t pid, int sig); //发信号
  
  int raise(int sig);//给当前进程/线程发信号
  
  unsigned int alarm(unsigned int seconds);  //SIGALARM 杀死当前进程。无法实现多任务
  
  int pause(void);
  
  void abort(void);
  
  int system(const char *command);
  
  unsigned int sleep(unsigned int seconds);
  ```

  > 变量的修饰关键字：volatile
  >
  > volatile的本意是“易变的” 因为访问寄存器要比访问内存单元快的多,所以编译器一般都会作减少存取内存的优化，但有可能会读脏数据。**当要求使用volatile声明变量值的时候，系统总是重新从它所在的内存读取数据**，即使它前面的指令刚刚从该处读取过数据。
  >
  > volatile 提醒编译器它后面所定义的变量随时都有可能改变，因此编译后的程序每次需要存储或读取这个变量的时候，都会**直接从变量地址中读取数据**。如 果没有 volatile 关键字，则编译器可能优化读取和存储，可能暂时使用寄存器中的值，如果这个变量由别的程序更新了的话，将出现不一致的现象。所以**遇到这个关键字声明的变量，编译器对访问该变量的代码就不再进行优化，从而可以提供对特殊地址的稳定访问**。

  

- 信号集和信号屏蔽字/pending集的处理

```c
// 信号集
#include <signal.h>

int sigemptyset(sigset_t *set);

int sigfillset(sigset_t *set);

int sigaddset(sigset_t *set, int signum);

int sigdelset(sigset_t *set, int signum);

int sigismember(const sigset_t *set, int signum);


//信号屏蔽字
/* Prototype for the glibc wrapper function */
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset); //决定信号什么时候响应
//pending集
int sigpending(sigset_t *set); //用不到
```



- 扩展操作

  ```c
  #include <signal.h>
  
  int sigsuspend(const sigset_t *mask); //实现信号驱动
  
  int sigaction(int signum, const struct sigaction *act,
                struct sigaction *oldact);
  
  ```



- 实时信号



#### 线程实现





















# 临时笔记

errno在目录/usr/include/asm-generic/errno.h中

将errno转换成错误信息的函数:

- perror("string"); //打印string+错误信息 
- strerror(errnum); //返回错误信息



ulimit -a 查看资源最多的情况

如何用touch命令创建一个名为-a的文件

```bash
[chuancey@AliUbuntu tmp]$ touch -a
touch: missing file operand
Try 'touch --help' for more information.

# 方法一 --表示当前的选项结束
[chuancey@AliUbuntu tmp]$ touch -- -a
[chuancey@AliUbuntu tmp]$ ls
-a

# 方法二
[chuancey@AliUbuntu tmp]$ touch ./-a
[chuancey@AliUbuntu tmp]$ ls
-a
```



stat命令可以查看文件的属性信息

static函数禁止外部扩展



- 使用ctag工具构建可以查看数据类型定义的方法

  ```bash
  # 安装catgs  CentOS环境
  sudo yum install ctags
  
  # 构建tags文件
  cd /usr/include
  sudo ctags -R
  
  # 将tags文件加到vim的配置文件中
  set tags=/usr/include/tags
  
  # 使用方法一
  vim -t EEXIST
  # 使用方法二：在已经用vim打开的文件中，ctrl+]来
  ```



- 删除文件可以用remove函数

  ```c
  #include <stdio.h>
  int remove(const char *pathname);
  ```

- 移动文件/重命名文件可以用rename文件

  ```c
  #include <stdio.h>
  int rename(const char *old, const char *new);
  ```



利用命令行给函数传参时，*和？当作通配符使用



root用户无法运行没有x权限的二进制文件，其他权限都可以执行。当一个文件的权限是000时，root可以读写。

打印时戳的命令：date +%s























