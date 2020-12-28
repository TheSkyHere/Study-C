#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define SERVER_PORT 8888
#define MAX_MSG_SIZE 1024

void udps_respon(int sockfd)
{
    struct sockaddr_in addr;
    int addrlen,n;
    char msg[MAX_MSG_SIZE];
    while(1)
    {
        //从网络上读取并写到网络上去
        bzero(msg,sizeof(msg));
        addrlen = sizeof(struct sockaddr);
        n = recvfrom(sockfd,msg,MAX_MSG_SIZE,0,(struct sockaddr*)&addr,&addrlen);
        msg[n] = 0;
        fprintf(stdout,"Server have received %s\n",msg);
    }
}

int main(void)
{
    int sockfd;
    struct sockaddr_in addr;
    //建立socket描述符
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(socket<0)
    {
        fprintf(stderr,"Socket Error:%s\n",strerror(errno));
        exit(1);
    }
    //服务器端填充数据
    bzero(&addr,sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(SERVER_PORT);

    //绑定sockfd描述符
    if(bind(sockfd,(struct sockaddr *)&addr,sizeof(struct sockaddr_in))<0)
    {
        fprintf(stderr,"Bin Error:%s\n",strerror(errno));
        exit(1);
    }
    udps_respon(sockfd);
    close(sockfd);
}