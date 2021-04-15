#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>

// 函数说明：

// 　　ftruncate()会将参数fd指定的文件大小改为参数length指定的大小。

// 　　参数fd为已打开的文件描述词，而且必须是以写入模式打开的文件。

// 　　如果原来的文件大小比参数length大，则超过的部分会被删去。

// 返回值：

// 　　执行成功则返回0，失败返回-1，错误原因存于errno。

main(int argc,char **argy)
{
    int out;
    // out=open("./aaaa.log",O_RDWR|O_CREAT,S_IRUSR ,0666);
    out=open("./aaaa.log", O_RDWR | O_APPEND | O_CREAT, 0666) ;;
    ftruncate(out,500);//相当于删除了部分内容
    close(out);
}