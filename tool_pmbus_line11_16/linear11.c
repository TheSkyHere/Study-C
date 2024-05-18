//linear11
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    short exponent;
    int mantissa;
    int val_x;

    mantissa = ((signed short)((strtoul(argv[1],0,0) & 0x7ff) << 5)) >> 5;
    // printf("%x\n",mantissa);
    exponent = ((signed short)strtoul(argv[1],0,0))>>11;
    // printf("%d\n",exponent);
    val_x = mantissa * 1000L;  //v转为mv

    if (exponent >= 0)
        val_x <<= exponent;  // 左移：* 2的exponent次方
    else
        val_x >>= -exponent; // 右移：/ 2的exponent（正）次方  即 * 2的 - exponent（正）次方
   printf("%d\n",val_x);
   return 0;
}