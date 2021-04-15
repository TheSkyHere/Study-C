#include <stdio.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>

#define SYNC_CHAR1 0x43
#define SYNC_CHAR2 0x4d

#define LEN1ForPayload 5
#define LEN2ForPayload 4

#define UART2 "/dev/ttyUSB0"
#define UART4 "/dev/ttyUSB1"

void main(void)
{
    int fd_y1,fd_y3;
    char buf[2048];
    char byte = 0X00;
    char last_byte = 0X00;
    char begin_flag = 0;
    int len,byte_len,payload_len;
    // sleep(10);
    fd_y1 = open(UART2, O_RDWR);  //block 
	while(fd_y1 < 0)  
    {  
        printf("Can't open %s !!!  and try again\n",UART2);
        sleep(1);
        fd_y1 = open(UART2, O_RDWR);  //block 
    }
    // fd_y3 = open(UART4, O_RDWR);  //block
	// while(fd_y3 < 0)  
    // {  
    //     printf("Can't open %s !!!  and try again\n",UART4);   
    //     sleep(1);
    //     fd_y3 = open(UART4, O_RDWR);  //block
    // }
    printf("Can't open !!!  and try again\n");



    
    sleep(5);
    while(1)//need see CPU
    {
        last_byte = byte;
        len = read(fd_y1, &byte,1);//block
        printf("byte=0x%x\n",byte);
        write(fd_y1,&byte,len);
        printf("write over \n");
        // write(fd_y3,&byte,len);
        printf("begin_flag = OX%x,last_byte = 0X%x,byte = 0X%0x\n",begin_flag,last_byte,byte);
        if((begin_flag==0)&&(last_byte==SYNC_CHAR1)&&(byte==SYNC_CHAR2))
        {
            printf("begin_flag = 1\n");
            begin_flag = 1;
            byte_len = 0;
            buf[byte_len++] = last_byte;
            buf[byte_len++] = byte;
            
        }
        else if(begin_flag==1)
        {
            buf[byte_len++] = byte;
            if(byte_len==LEN1ForPayload+1)
            {
                payload_len = (buf[LEN2ForPayload])+buf[LEN1ForPayload];
                printf("payload_len = %d \n",payload_len);
            }
            else if((byte_len)>(1+1+1+1+2+payload_len+1)) //packet finash
            {
                begin_flag=0;

                printf("packet finash byte_len=%d\n",byte_len-1);
                for(int i=0;i<byte_len-1;i++)
                {
                    printf("%d,data=0x%x\n",i,buf[i]);
                }
                
            }
        }
    }
    close(fd_y1);
    close(fd_y3);
    return 0;
}