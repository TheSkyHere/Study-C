/* 2019.12.28  practice 

fcntl函数有5种功能：

复制一个现有的描述符(cmd=F_DUPFD).
获得／设置文件描述符标记(cmd=F_GETFD或F_SETFD).
获得／设置文件状态标记(cmd=F_GETFL或F_SETFL).
获得／设置异步I/O所有权(cmd=F_GETOWN或F_SETOWN).
获得／设置记录锁(cmd=F_GETLK , F_SETLK或F_SETLKW).



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
int main(int argc, char **argv)
{    
    fd_set fdset;    
	struct timeval tv;
	tv.tv_sec = 5;
	tv.tv_usec = 0;
	int fd,retval;
	char str[]="1234567890";
	char buf[20];
	int len;
	int flags;
	int ret,access;
	



// 1、获取文件的flags，即open函数的第二个参数:
// flags = fcntl(fd,F_GETFL,0);

// 2、设置文件的flags:
// fcntl(fd,F_SETFL,flags);

// 3、增加文件的某个flags，比如文件是阻塞的，想设置成非阻塞:
// flags = fcntl(fd,F_GETFL,0);
// flags |= O_NONBLOCK;
// fcntl(fd,F_SETFL,flags);

// 4、取消文件的某个flags，比如文件是非阻塞的，想设置成为阻塞:
// flags = fcntl(fd,F_GETFL,0);
// flags &= ~O_NONBLOCK;
// fcntl(fd,F_SETFL,flags);

	printf("===================fcntl test bdgin====================== \n\n\n");
	
	fd = open("file_1",O_RDONLY | O_CREAT,(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH));
	if(fd<0)
	{
		printf("open file err");
		return -1;
	}




	printf("===================fcntl test F_DUPFD ====================== \n");
	ret = fcntl(fd, F_DUPFD, 0);//Duplicate file descriptor   fd ~=ret
	printf("ret= 0x%x fd=0x%x\n",ret,fd);

	len = read(ret,buf,2);
	printf("ret------buf : %s,len : %d\n", buf, len); 

	len = read(fd,buf,2);
	printf("fd-------buf : %s,len : %d\n\n\n", buf, len); 




	printf("===================fcntl test F_GETFL ======================== \n");
	ret = fcntl(fd, F_GETFL, 0);
	printf("ret=0x%x\n",ret);
	access = ret & O_ACCMODE;
	switch (access) {
	case O_RDWR:
		printf("read write mode\n");
		break;
	case O_RDONLY:
		printf("read only mode\n");
		break;
	case O_WRONLY:
		printf("write only mode\n");
		break;
	default:
		printf("unknown access mode\n");
		break;
	}
// F_SETFL命令允许更改的标志有O_APPEND,O_NONBLOCK,O_NOATIME,O_DIRECT,O_ASYNC
// https://blog.csdn.net/weixin_30911809/article/details/96572964
	printf("===================fcntl test F_SETFL ====================== \n");
	ret = fcntl(fd, F_SETFL,access|O_NONBLOCK);// ret is O_RDONLY
	ret = fcntl(fd, F_GETFL, 0);// ret is O_RDONLY
	printf("ret=0x%x\n",ret);



///* 设置为非阻塞*/
//int flags;
//if (fcntl(socket_descriptor, F_SETFL, flags | O_NONBLOCK) < 0)
//{
///* Handle error */
//}

///* 设置为阻塞 */
//if ((flags = fcntl(fd, F_GETLK, 0)) < 0)
//{
///* Handle error */
//printf("ERR");
//}


	close(fd);
    return 0;
}
