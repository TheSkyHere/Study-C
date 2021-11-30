#include "stdio.h"
//by sky
int main(){
    short i = 0x0102;//十六进制，高字节为1，底字节为2。 
    char t[2];//t[0]在内存底地址，t[1]在内存高地址。 
    
	/*取i的指针&i，将这个指针转为char*型，依次取出i的每个字节的值。*/ 
    t[0] = *((char*)&i+0); 
    t[1] = *((char*)&i+1);
    
    if(t[0]==1&&t[1]==2)
        printf("大端！\n");
    else if(t[0]==2&&t[1]==1)
        printf("小端！\n");
    else
        printf("......\n");
        
    return 0;
}