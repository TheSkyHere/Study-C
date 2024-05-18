// linear16
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    short exponent;
    int mantissa;
    int val_x;

    mantissa = (signed short)strtoul(argv[1],0,0);
    exponent = ((signed short)(0x16 << 11)) >> 11 ;

    val_x = mantissa * 1000L;
    if (exponent >= 0)
        val_x <<= exponent;
    else
        val_x >>= -exponent;
   printf("%d\n",val_x);
   return 0;
}
