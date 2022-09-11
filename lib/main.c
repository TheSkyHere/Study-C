#include <stdio.h>
// #include "api.h"
#include <dlfcn.h>

 
//直接调用  
// 编译指令：gcc main.c api.c api.h -o test 
// int main()
// {
//     test();
//     return 0;
// }

// //编译时引入lib库 
// //编译库：gcc -shared -o libapi.so api.c 
// //把库拷贝到lib下：运行可执行文件的时候需要用到这个库，cp ./libapi.so ~/usr/local/lib 
// //更新linux下的库sudo ldconfig 
// //编译可执行文件：gcc main.c  -o test -L ./ -lapi   （编译时候需要使用到库指定库在当前目录下，和运行的时候是不一样的）
// int main()
// {
//     test(0);
//     return 0;
// }


// //调用动态库
// //编译指令：gcc main.c  -o test-1  -ldl 
// int main()
// {
//     /*手动加载指定位置的so动态库*/
//     void* handle = dlopen("./libapi.so", RTLD_LAZY);
//     int (*test)();

//     /*根据动态链接库操作句柄与符号，返回符号对应的地址*/
//     *(void**)(&test) = dlsym(handle, "test");

//     test();
//     printf("main --over\n");

//     dlclose(handle);
//     return 0;
// }



// int main()
// {
//     void *handle = dlopen("./libapi.so", RTLD_LAZY);
//     int (*test)(int vol);
//     int (*test_1)(int vol);
//     *(void**)(&test)  = dlsym(handle, "test");
//     *(void**)(&test_1) = dlsym(handle, "test_1");
//     while(1){
//         test(1);
//         test_1(1);
//         sleep(3);
//     }
    
//     printf("matao ---test");
//     dlclose(handle);
//     return 0;

// }