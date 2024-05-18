#include <stdio.h>
#include <fcntl.h>
#include <string.h>
// int main(int argc,char **argv)
// {
//     int fd,ret;
//     unsigned char key_val;  
//     system("echo abc >te.log");

//     printf("argv[0]%s \nargv[1]:%s\n",argv[0],argv[1]);

//     //将字符串里的数字字符转化为整形数。返回整形值。
//     fd=atoi(argv[0]);
//     char str[16];
//     ret = read(fd, &key_val, 1);//fd >>n after read  
//     printf("test key_val: 0x%x, ret = %d fd = %d\n", key_val, ret,fd);  
//     sleep(10);
//     printf("test over\n");
// return 0;


int main(int argc,char **argv)
{
    int fd;
    fd=atoi("-1500");
    printf("test , fd = %d\n",fd);  
    sleep(10);
    printf("test over\n");
return 0;
}