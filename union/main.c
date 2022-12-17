#include <stdio.h>
#include <string.h>

union Data
{
   int i;
   float f;    //存储格式需要在学习一下
   char str[20];
};


int main()
{
    union Data data;
    

    data.i=0x32;
    printf("matao---test %d,%f,%c",data.i,data.f,data.str[19]);

    for(int i=0;i<20;i++)
    {   
        //通过这也可以观察出CPU的大小端，
        memset(data.str,"\0",20);
        data.i=0x32;
        printf("matao---test str[%d]%c\n",i,data.str[i]);
    }


}