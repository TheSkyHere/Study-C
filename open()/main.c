#include <stdio.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>
// open()  from linux
// fopen() from C 

//study: 
// https://blog.csdn.net/xiaodingqq/article/details/79931662
// https://blog.csdn.net/qq_36754075/article/details/105646555

int main(int argc, char **argv)  
{  
    unsigned char key_val;  
    int ret;  
    int Oflags;  
    int fd,fd1;
    
    // fd = open("file-1", O_RDWR | O_CREAT,S_IREAD); //S_IREAD = S_IRUSR
    fd = open("file-1", O_RDWR | O_CREAT,(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH|S_IWOTH|S_IXOTH));  //WR|if no file and creat   note: fd is int
    //note umask 
    system("ls -all ");
    system("chmod o+w ./file-1");
    system("ls -all ");

    printf("fd1 = %d\n",fd);  
    // fd = open("file-1", O_RDWR | O_CREAT | O_NONBLOCK,,(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH));  //WR|if no file creat|NO block 非阻塞方式运行
    if (fd < 0)  
    {  
        printf("can't open! fd\n");  
        return -1;  
    }
    // fd1 = open("file-1", O_RDWR | O_CREAT,(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH));  //WR|if no file and creat   note: fd is int
    // printf("fd1 = %d\n",fd1);  
    fd1 = open("/dev/ttyUSB0", O_RDWR);  //阻塞方式运行  need root
    printf("fd1 = %d\n",fd1);  
    if (fd1 < 0)  
    {  
        printf("can't open! fd1\n");  
        return -1;  
    }
     
    int i =4;
    printf("read fd1----------------\n"); 
    while (i--)  
    {  
        ret = read(fd1, &key_val, 1);//fd >>n after read  
        printf("key_val: 0x%x, ret = %d\n", key_val, ret);  
        sleep(1);
    }

    i=4;
    printf("read fd----------------\n"); 
    while (i--)  
    {  
         
        ret = read(fd, &key_val, 1);//fd >>n after read  
        printf("key_val: 0x%x, ret = %d\n", key_val, ret);  
        sleep(1);
    }
    close(fd);
    close(fd1);
    return 0;  
} 
