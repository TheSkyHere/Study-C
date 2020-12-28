#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int set_fd(int);
int main()
{
        int fd,ret;
        char f1[20];
        char f2[20]="987654321";
        fd=open("/home/morton/workspace/workspace-C/fcntl_execl/pighead.txt",O_RDWR|O_CREAT,(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH));
        if(fd<0)
        {
                printf("Fail read err \n");
                return 0;
        }
        set_fd(fd);
        sprintf(f1,"%d",fd);

        //直接使用./test 123 321  和通过execl调用test最终argv参数不同
        // execl 在执行完之后，原调用进程的内容除了进程号外，其他全部被新程序的内容替换了,一般使用fork ，让子进程重生 subprocess will die
        // study:
        //https://blog.csdn.net/amoscykl/article/details/80354052
        ret=execl("/home/morton/workspace/workspace-C/fcntl_execl/test",f1,(char *)0);
        printf("main ret:%d \n",ret);
        close(fd);
        return 0;
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

