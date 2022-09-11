/* 2019.12.28  practice 
 *
 * int select(int nfds, fd_set *readfds,fd_set *writefds,fd_set *exceptdes,struct timeval *timeout); //monitoring multiple descriptions FD
 * readfds：监视文件描述符的一个集合，我们监视其中的文件描述符是不是可读，或者更准确的说，读取是不是不阻塞了。
 * writefds：监视文件描述符的一个集合，我们监视其中的文件描述符是不是可写，或者更准确的说，写入是不是不阻塞了。
 * exceptfds：用来监视发生错误异常文件
 * timeout:timeout表示select返回之前的时间上限。如果timeout==NULL，无期限等待下去，这个等待可以被一个信号中断，只有当一个描述符准备好，或者捕获到一个信号时函数才会返回。如果是捕获到信号，select返回-1，并将变量errno设置成EINTR。
 * struct timeval{
 *     long tv_sec;//秒
 *     long tv_usec;//微秒
 * }
 * 
 * 
 * void FD_CLR(int fd,fd_set * set);     //clear FD
 * int  FD_ISSET(int fd, fd_set *set);	 //test FD on aggregate														
 * void FD_SET(int fd, fd_set *set);	 //add FD to aggregate
 * void FD_ZERO(fd_set *set);			 //init aggregate
 * 
#include <sys/select.h> /* 根据POSIX.1 - 2001 */
/*根据早期的标准*/
#include<sys/types.h>
#include<sys/time.h>
#include<unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<sys/stat.h>
#include<fcntl.h>
#define SSIZE_MAX 10 

//test select() 函数，通过入参0 or 1 来测试普通文件和驱动文件
int main(int argc, char **argv)
{    
	fd_set fdset;    
	struct timeval tv;
	tv.tv_sec = 5;
	tv.tv_usec = 0;
	int retval;
	char str[]="1234567890";
	char buf[20];
	int len;
	int flags;
	int fd1,fd2,fd3,fd4,skfd,MAXfd;


	printf("TEST: argc=%d \n",argc);
	if(argc<2)
	{
		printf("Please input second parameter\n"); //second parameter ->argy[1]
		return 0;
	}
    printf("TEST:\n argy[0]=%s\n argy[1]=%s\n *argy[1]=%x\n",argv[0],argv[1],*argv[1]); //second parameter ->argy[1]

	if(*argv[1]==0x31)
	{
		printf("========================================================\n===========Test TRACK 1 ===========\n\n");
		goto TRACK;
	}
	else if(*argv[1]==0x30)
	{
		printf("========================================================\n===========Test TRACK 0 ===========\n\n");
	}
	else
	{
		printf("Err: second parameter is 0 or 1 \n"); //second parameter ->argy[1]
		return 0;
	}
	

	
	printf("open \n");

	fd1 = open("file-1", O_RDWR | O_CREAT,(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH|S_IWOTH|S_IXOTH));
	if (fd1 < 0)  
    {  
        printf("can't open fd1 !!!\n");   
    }
	fd2 = open("file-2", O_RDWR | O_CREAT,(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH|S_IWOTH|S_IXOTH));
	if (fd2 < 0)  
    {  
    	printf("can't open fd2 !!!\n");   
    }
	fd3 = open("file-3", O_RDWR | O_CREAT,(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH|S_IWOTH|S_IXOTH));
	if (fd3 < 0)  
    {  
        printf("can't open fd3 !!!\n");   
    }
	fd4 = open("file-4", O_RDWR | O_CREAT,(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH|S_IWOTH|S_IXOTH));
	if (fd4 < 0)  
    {  
        printf("can't open fd4 !!!\n");   
    }




    FD_ZERO (&fdset);                          /*清空集合中所有的元素*/    

    FD_SET(fd1,&fdset);              /*设置stdout，使集合中包含stdout*/  
	FD_SET(fd2,&fdset);              /*设置stdout，使集合中包含stdout*/  
	FD_SET(fd3,&fdset);              /*设置stdout，使集合中包含stdout*/  
	FD_SET(fd4,&fdset);              /*设置stdout，使集合中包含stdout*/  

	printf("fd1=%d,fd2=%d,fd3=%d,fd4=%d\n",fd1,fd2,fd3,fd4);
	MAXfd=fd1;
	if(MAXfd<fd2)
	{
		MAXfd=fd2;
	}
	if(MAXfd<fd3)
	{
		MAXfd=fd3;
	}
	if(MAXfd<fd4)
	{
		MAXfd=fd4;
	}
	MAXfd=MAXfd+1;

	printf("select\n");
	printf("fd=%d\n",MAXfd);
	retval = select(MAXfd,&fdset,NULL,NULL,NULL);
	if(retval == -1)
	{
		printf("Fail return -1");
	}
	printf("fdset = 0x%x\n",fdset);


	if(FD_ISSET(fd1,&fdset)!=0)      /*测试stdout是否包含在集合中*/        
		printf("1 stdout has been set\n");    
	else        
		printf("1 stdout has not been set\n");

	if(FD_ISSET(fd2,&fdset)!=0)      /*测试stdout是否包含在集合中*/        
		printf("2 stdout has been set\n");    
	else        
		printf("2 stdout has not been set\n");

	if(FD_ISSET(fd3,&fdset)!=0)      /*测试stdout是否包含在集合中*/        
		printf("3 stdout has been set\n");    
	else        
		printf("3 stdout has not been set\n");

	if(FD_ISSET(fd4,&fdset)!=0)      /*测试stdout是否包含在集合中*/        
		printf("4 stdout has been set\n");    
	else        
		printf("4 stdout has not been set\n");





	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	printf("Main is over \n");
    return 0;


	TRACK:
	fd1 = open("/dev/ttyUSB0", O_RDWR);  //阻塞方式运行  need root
	if (fd1 < 0)  
    {  
        printf("can't open ttyUSB0 !!!\n");   
    }
	fd2 = open("/dev/ttyUSB1", O_RDWR);  //阻塞方式运行  need root
	if (fd2 < 0)  
    {  
        printf("can't open ttyUSB1 !!!\n");   
    }

	FD_ZERO (&fdset);                          /*清空集合中所有的元素*/    

    FD_SET(fd1,&fdset);              /*设置stdout，使集合中包含stdout*/  
	FD_SET(fd2,&fdset);              /*设置stdout，使集合中包含stdout*/  



	MAXfd=fd1;
	if(MAXfd<fd2)
	{
		MAXfd=fd2;
	}
	MAXfd=MAXfd+1;

	printf("select\n");
	printf("fd=%d\n",MAXfd);
	retval = select(MAXfd,&fdset,NULL,NULL,NULL);
	if(retval == -1)
	{
		printf("Fail return -1");
	}
	printf("fdset = 0x%x\n",fdset);


	if(FD_ISSET(fd1,&fdset)!=0)      /*测试stdout是否包含在集合中*/        
		printf("1 stdout has been set\n");    
	else        
		printf("1 stdout has not been set\n");

	if(FD_ISSET(fd2,&fdset)!=0)      /*测试stdout是否包含在集合中*/        
		printf("2 stdout has been set\n");    
	else        
		printf("2 stdout has not been set\n");

	close(fd1);
	close(fd2);
	printf("Main is over \n");

}
