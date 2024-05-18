//linear11
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char ** argv)
{
    short exponent;
    int mantissa;
    int val_x;


	printf("%d\n",sizeof(char));
	
    printf("%d\n",sizeof(short));
	
    printf("%d\n",sizeof(int));
	
    printf("%d\n",sizeof(long));
	
    printf("%d\n",sizeof(long long));
	
    printf("%d\n",sizeof(float));
	
    printf("%d\n",sizeof(double));
 

    int8_t value_h = -32;
    int16_t value_l = 0xfc;
    int16_t value = (((uint8_t)value_h) << 8) | ((uint8_t)value_l);

char a = -1;
unsigned char p = -1;




uint32_t matao1 = value_h | 0x000000;
printf("matao:%x\n",matao1);

printf("%#x,%#x \n", a, p);  // 原式
printf("%#x,%#x \n", (char)-1, (unsigned char)-1);  // 代入具体值
printf("%#x,%#x \n", (int)(char)-1, (int)(unsigned char)-1);  // 标识符对应整型
printf("%#x,%#x \n", (int)(char)0xff, (int)(unsigned char)0xff);  // 十六进制形式
printf("%#x,%#x \n", (int)0xffffffff, (int)0x000000ff);  // 符号扩展
printf("0xffffffff,0xff\n");  // 结果




    printf("value=0x%x value_h=0x%d   value_l=0x%x  value_h=0x%x   value_l=0x%x\n",value,value_h,value_l,value_h,(int16_t)value_l);

    mantissa = ((signed short)((value) & 0x7ff) << 5) >> 5;
    // printf("%x\n",mantissa);
    exponent = ((signed short)value)>>11;
    // printf("%d\n",exponent);
    val_x = mantissa * 1000L;  //v转为mv

    if (exponent >= 0)
        val_x <<= exponent;  // 左移：* 2的exponent次方
    else
        val_x >>= -exponent; // 右移：/ 2的exponent（正）次方  即 * 2的 - exponent（正）次方
   printf("%d\n",val_x);
   return 0;
}