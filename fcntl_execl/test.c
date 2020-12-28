#include <stdio.h>
#include <fcntl.h>
#include <string.h>
int main(int argc,char **argv)
{
    int fd,ret;
    system("echo MT test >te.log");
    printf("test begin argv[0]%s \nargv[1]:%s\n",argv[0],argv[1]);


    //将字符串里的数字字符转化为整形数。返回整形值。
    fd=atoi(argv[0]);
    char str[16];
    strcpy(str,"hello,world~\n");

    printf("write data :%s\n",str);
    ret=write(fd,str,strlen(str));
    if(ret<0)
    {
        printf("Fail write err:%d/n",ret);
    }
    close(fd);
    return 0;
}