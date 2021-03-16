# 运行流程



![img](https://images2017.cnblogs.com/blog/422590/201711/422590-20171110141226856-793077190.png)

# 过程记录





编译源程序是在 sparc solaris 2.6 下编译的，在 linux 下编译需要进行修改：





Ubuntu 有专门的工具方便的开放本地端口 ：（替代了繁琐的iptables配置）

sudo ufw allow 53 允许外部访问53端口(tcp/udp)



源代码需要从官方地址下载，别人修改后的不要随便用。尝试了好久，出现各种问题

链接参数 -l pthread放在编译参数的后面，否则可能会编译出错 



设置vim的gg=G 的自动格式话的代码缩进字符为4

```bash
set tabstop=4 softtabstop=4 shiftwidth=4 expandtab
```





```c
/*
strcmp和strcasecmp
*/
// 在忽略大小写的情况下比较s1和s2两个串
int strcasecmp(const char *s1, const char *s2);
```









