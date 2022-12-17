#include<stdio.h>


typedef struct MT_STRUCT_BIT
{
    int a:2;
    int b:2;
    int c:2;
    int d:2;
}mt_struct_bit;


union Data
{
   int i;
   mt_struct_bit data_bit;
};


int main()
{
    union Data data;
    data.data_bit.a=0x01;
    data.data_bit.b=0x00;
    data.data_bit.c=0x00;
    data.data_bit.d=0x03;
    printf("matao---test 0x%x\n",data.i);
    
}