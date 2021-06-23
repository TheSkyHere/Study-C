#include<stdio.h>
#include<unistd.h>


// execve() – 叫做执行程序函数
// 就像Python中的os.system(cmd)这个函数，我们可以用这个函数来执行我们的shell脚本，单独的shell命令，或者是调用其他的程序，我们的execve()这个函数就和Python中的os.system函数类似，可以调用其他程序的执行，执行shell命令，，调用脚本等等功能。


int main(int arg, char **args)
{
    char *argv[]={"ls","-al","/home/morton/", NULL};

    char *envp[]={0,NULL}; //传递给执行文件新的环境变量数组

    execve("/bin/ls",argv,envp);

}




