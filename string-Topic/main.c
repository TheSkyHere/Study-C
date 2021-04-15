#include <stdio.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <string.h>

// char *strcpy(char *dest, const char *src);  // copy all string to dest from src, if dest biger src of buf will buffer overflow
// char *strncpy(char *dest, const char *src ,int n);  // copy n strings to dest from src, NOTE:NULL
//strlen
//strcmp

//定义函数：char * strdup(const char *s);
//函数说明：strdup()会先用maolloc()配置与参数s 字符串相同的空间大小，然后将参数s 字符串的内容复制到该内存地址，然后把该地址返回。该地址最后可以利用free()来释放。

// 定义函数：char * index(const char *s, int c);
// 函数说明：index()用来找出参数s 字符串中第一个出现的参数c 地址，然后将该字符出现的地址返回。字符串结束字符(NULL)也视为字符串一部分。
// 返回值：如果找到指定的字符则返回该字符所在地址，否则返回0.

// 定义函数：char * rindex(const char *s, int c);
// 函数说明：rindex()用来找出参数s 字符串中最后一个出现的参数c 地址，然后将该字符出现的地址返回。字符串结束字符(NULL)也视为字符串一部分。
// 返回值：如果找到指定的字符则返回该字符所在的地址，否则返回0。

// itoa()
// atoi()
//memset()
//memcopy
// void *memcpy(void *str1, const void *str2, size_t n)
// 参数
// str1 -- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针。
// str2 -- 指向要复制的数据源，类型强制转换为 void* 指针。
// n -- 要被复制的字节数。
// https://www.runoob.com/cprogramming/c-standard-library-string-h.html

//fscanf 函数原型为 int fscanf(FILE * stream, const char * format, [argument...]); 
//其功能为根据数据格式(format)，从输入流(stream)中读入数据，存储到argument中，遇到空格和换行时结束。fscanf位于C标准库头文件<stdio.h>中。 [1]


main(int argc ,char **argy)
{
    if(argc!=2){
        printf("need parament \n example:%s strcpy/strncpy/.... \n",argy[0]);
        fprintf(stderr,"Usage:%s\n\a",argy[0]);
        return 0;
    }

    if(0==strcmp(argy[1], "strcpy")){
        char str_1[56] = "1234567890abcdefghijklm";
        char str_2[56] = "abcdefghijklmnopqrstuvwxyz";
        char str_3[56] ;
        printf("strcpy(str_3,str_1)=%s\n",strcpy(str_3,str_1));
        printf("strcpy(str_3,str_2)=%s\n",strcpy(str_3,str_2));
        printf("strcpy(str_2,str_1)=%s\n",strcpy(str_2,str_1));
        for(int i=0;i<56;i++){
            printf("str_2[%d]=%c:0x%x\n",i,str_2[i],str_2[i]);
        }
    }
    else if(0==strcmp(argy[1], "strncpy")){
        char str_1[56] = "1234567890abcdefghijklm";
        char str_2[56] = "abcdefghijklmnopqrstuvwxyz";
        char str_3[56] ;
        printf("strncpy(str_3,str_1,5)=%s\n",strncpy(str_3,str_1,5));
        printf("strncpy(str_3,str_2,56)=%s\n",strncpy(str_3,str_2,56));
        printf("strncpy(str_2,str_1,strlen(str_1))=%s\n",strncpy(str_2,str_1,strlen(str_1)));
        for(int i=0;i<56;i++){
            printf("str_2[%d]=%c:0x%x\n",i,str_2[i],str_2[i]);
        }
    }
    else if(0==strcmp(argy[1], "strlen")){
        char str_1[56] = "1234567890abcdefghijklm";
        char str_2[56] = "abcdefghijklmnopqrstuvwxyz";
        char str_3[56] ={};
        printf("strlen(str_1)=%d\n",strlen(str_1));
        printf("strlen(str_2)=%d\n",strlen(str_2));
        printf("strlen(str_3)=%d\n",strlen(str_3));
    }
    else if(0==strcmp(argy[1], "strdup")){
        char a[] = "strdup";
        char *b;
        b = strdup(a);
        printf("b[]=\"%s\"\n", b);
    }
    else{
        printf("para is err\n");
    }


    


}

