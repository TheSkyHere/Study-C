#include "stdio.h"
#include "stdlib.h"
//by sky

void test(char *str)
{
    printf("test len=%d \n",sizeof(str));
}


int main()
{
    char str[] = "啊我啊我啊我啊我";
    printf("main len=%d \n",sizeof(str));
    test(str);

    return 0;
}