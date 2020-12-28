#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#if 0

	struct hostent
	{
		char *h_name;         //正式主机名
		char **h_aliases;     //主机别名
		int h_addrtype;       //主机IP地址类型：IPV4-AF_INET
		int h_length;		  //主机IP地址字节长度，对于IPv4是四字节，即32位
		char **h_addr_list;	  //主机的IP地址列表
	};
	
	#define h_addr h_addr_list[0]   //保存的是IP地址

#endif

#define portnumber 333
int main (int argc,char * argv[])
{
    int sockfd;
    char buffer[1024];
    struct sockaddr_in server_addr;
    struct hostent *host;
    //使用host查询host 名字
    if(argc!=2)
    {
        fprintf(stderr,"Usage:%s hostname \a\n",argv[0]);
        exit(1);
    }

    if((host=gethostbyname(argv[1]))==NULL) //通过域名获取 host 实际如参可以是字符串 IP 
    {
        fprintf(stderr,"Gethostname error \n");
        exit(1);
    }




    printf("official hostname: %s\n",host->h_name);//正式主机名
    char *ptr,**pptr;
    char str[INET_ADDRSTRLEN];
    for(pptr=host->h_aliases;*pptr!=NULL;pptr++)//遍历所有的主机别名
        printf("\talias: %s\n",*pptr);

    switch(host->h_addrtype)//判断socket类型
    {
        case AF_INET:  //IP类为AF_INET
            pptr=host->h_addr_list; //IP地址数组
            for(;*pptr!=NULL;pptr++)
                printf("address: %s\n",inet_ntop(host->h_addrtype,*pptr,str,sizeof(str)));//inet_ntop转换为点分十进制
            break;
        default:
            printf("unknown address type\n");
            break;
    }





    //客户程序开始建立 sockfg 描述符
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) //使用是AF_INET IPV4的协议，SOCK_STREAM是TCP协议
    {
        fprintf(stderr,"Socket Error %s\a\n",strerror(errno));
        exit(1);
    }
    //填充服务端资料
    bzero(&server_addr,sizeof(server_addr)); //置0
    server_addr.sin_family = AF_INET;  //IPV4
    server_addr.sin_port = htons(portnumber);//将本机上的short数据转换成网络上的short数据
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);//IP地址

    //发起连接
    if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
    {
        fprintf(stderr,"Connect Error:%s \a\n",strerror(errno));
        exit(1);
    }
    printf("please imput char:\n");
    //读取数据
    fgets(buffer,1024,stdin);
    //发送数据
    write(sockfd,buffer,strlen(buffer));

    close(sockfd);
    exit(1);
    

}