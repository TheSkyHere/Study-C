#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <fcntl.h>


#include <wait.h>

#define PERM S_IRUSR|S_IWUSR
//share mem

int set_fd(int fd);
int main(int argc, char **argy)
{
    unsigned char key_val;  
    int ret;  
    int Oflags;  
    int fd;
    char f1[10];

    printf("TEST argc=%d \n",argc);
    printf("TEST argy=%s\n",argy[1]); //second parameter ->argy[1]

    // fd = open("file-1", O_RDWR | O_CREAT,S_IREAD); //S_IREAD = S_IRUSR
    // fd = open("/home/morton/workspace/workspace-C/open-fork-execl/file-1", O_RDWR | O_CREAT,(0777));  //WR|if no file and creat   note: fd is int
    fd = open("/home/morton/workspace/workspace-C/open-fork-execl/file-1", O_RDWR | O_CREAT,(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH));  //WR|if no file and creat   note: fd is int
    // fd = open("file-1", O_RDWR | O_CREAT | O_NONBLOCK,,(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH));  //WR|if no file creat|NO block 非阻塞方式运行
    if (fd < 0)  
    {  
        printf("can't open!\n");  
        return -1; 
    }





    // subprocess
    if(fork())
    {
        ret = read(fd, &key_val, 1);//fd >>n after read  
        printf("sub process key_val : 0x%x, ret = %d fd = %d\n", key_val, ret,fd);  
        sleep(1);
        printf("main process \n");  
        wait(NULL);
        printf("main---sub process over\n"); 
    }
    else
    {
        sleep(1);
        ret = read(fd, &key_val, 1);//fd >>n after read  
        printf("sub process key_val: 0x%x, ret = %d fd = %d\n", key_val, ret,fd);  
        sleep(1);
        printf("sub process over\n");

        set_fd(fd);
        sprintf(f1,"%d",fd);
        ret=execl("/home/morton/workspace/workspace-C/open-fork-execl/test",f1,(char *)0);
        printf("Fail main ret:%d \n",ret);

    }
    printf("main over\n");
}

int set_fd(int fd)
{
        unsigned int flag;
        flag=fcntl(fd,F_GETFD);
        // **FD_CLOEXEC **
        // close on exec, not on-fork 意思是如果对描述符设置了FD_CLOEXEC,使用execl执行的程序里,此描述符被关闭，
        // 此描述符不能再被使用. 但是在使用fork产生的子进程中此描述符不被关闭，仍然可以使用。
        flag|=~FD_CLOEXEC; //去掉'~'看看
        fcntl(fd,F_SETFD,flag);
        return 0;
}