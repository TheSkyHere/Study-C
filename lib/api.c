#include "api.h"



// 编译动态库 libapi.so
// 编译指令：gcc -shared -o libapi.so api.c   
void test()
{
    printf("matao-test api\n");
    matao();
}