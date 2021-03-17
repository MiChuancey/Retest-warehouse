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



GET 请求头

```http
GET / HTTP/1.1
Host: 192.168.164.128:4444
Connection: keep-alive
Cache-Control: max-age=0
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
Accept-Encoding: gzip, deflate
Accept-Language: zh-CN,zh;q=0.9,en;q=0.8,zh-HK;q=0.7
```



待解决的问题：

stat的相对路径问题





颜色不显示的原因：

- cgi脚本没有可执行权限
- cgi脚本中的perl解释器路径错误



