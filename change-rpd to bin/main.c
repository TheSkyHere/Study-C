#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define BIT0 0x0001
#define BIT1 0x0002
#define BIT2 0x0004
#define BIT3 0x0008
#define BIT4 0x0010
#define BIT5 0x0020
#define BIT6 0x0040
#define BIT7 0x0080


int convert(unsigned char *buf_in, unsigned char *buf_out, int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        buf_out[i] = ((buf_in[i] & BIT0) << 7) | 
                     (((buf_in[i] >> 1) & BIT0) << 6) | 
                     (((buf_in[i] >> 2) & BIT0) << 5) | 
                     (((buf_in[i] >> 3) & BIT0) << 4) | 
                     (((buf_in[i] >> 4) & BIT0) << 3) | 
                     (((buf_in[i] >> 5) & BIT0) << 2) | 
                     (((buf_in[i] >> 6) & BIT0) << 1) | 
                     (( buf_in[i] >> 7) & BIT0);
#if 0
        printf(" %02x-%02x", buf_in[i], buf_out[i]);
        if(i % 16 == 0)
        {
            printf("\n");
        }
#endif
    }

    return 0;
}

int main(int argc, char const *argv[])
{
	FILE *in,*out;
	char const * src_path = argv[1];    //要被拷贝的文件路径
	char const * des_path = argv[2];	//拷贝的文件放在哪里（路径）
    unsigned char buff_in[1024] = {0};
    unsigned char buff_out[1024] = {0};
    int length;

	in = fopen(argv[1],"r+");
	out = fopen(argv[2],"w+");

#if 1
	while(length = fread(buff_in,1,sizeof(buff_in),in))
	{
        convert(buff_in, buff_out, length);
		fwrite(buff_out,1,length,out);
	}
#else
	while(length = fread(buff_in,1,sizeof(buff_in),in))
	{
        //convert(buff_in, buff_out, length);
		fwrite(buff_in,1,length,out);
	}
#endif

	return 0;
}