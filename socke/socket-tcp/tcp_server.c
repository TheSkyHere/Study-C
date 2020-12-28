#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define portnumber 333



int main(int argc, char *argv[])
{
    int sockfd,new_fd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int sin_size;
    int nbytes;
    char buffer[1024];
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        fprintf(stderr,"Socket serror: %s\n\a",strerror(errno));
        exit(1);
    }
    //填充服务端
    bzero(&server_addr,sizeof(struct sockaddr_in));//初始化，置0
    server_addr.sin_family=AF_INET;    //internet IPV4
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY); //可以使用本地的任何一个地址通信 将本机long数据转换成网络上的long
    // server_addr.sin_addr.s_addr = inet_addr("192.168.2.190");//获取本级IP
    server_addr.sin_port=htons(portnumber);//将本机上的short数据转换成网络上的short数据
    if(bind(sockfd,(struct sockaddr*)(&server_addr),sizeof(struct sockaddr))==-1)
    {
        fprintf(stderr,"Bind error:%s\n\a",strerror(errno));
        exit(1);
    }

    if(listen(sockfd,5)==-1)
    {
        fprintf(stderr,"Listen error:%s\n\a",strerror(errno));
        exit(1);
    }

    while(1)
    {
        //服务其阻塞直到客户端程序建立连接
        sin_size=sizeof(struct sockaddr_in);
        if((new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size))==-1)
        {
            fprintf(stderr,"Accept error:%s \n\s",strerror(errno));
            exit(1);
        }

        fprintf(stderr,"Server get connection from %s\n",inet_ntoa(client_addr.sin_addr));
        if((nbytes=read(new_fd,buffer,1024))==-1)
        {
            fprintf(stderr,"Read Error:%s\n",strerror(errno));
            exit(1);
        }
        buffer[nbytes]='\0';
        printf("Server received %s\n",buffer);

        close(new_fd);
    }


}