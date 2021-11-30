#include <stdio.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>


// C语言str函数系列
// https://blog.csdn.net/KangRoger/article/details/24383571

// strcat()
// 此函数原型为 char *strcat(char *dest, const char *src).
// 功能为连接两个字符串，把src连接到dest后面；返回dest地址

// strcmp()
// 此函数的函数原型为 int strcmp(const char *str1, const char *str2).
// 功能为比较两个字符串。
// 当str1指向的字符串大于str2指向的字符串时，返回正数。
// 当str1指向的字符串等于str2指向的字符串时，返回0。
// 当str1指向的字符串小于str2指向的字符串时，返回负数。
// strncmp()

// strcpy()
// 此函数原型为 char *strcpy(char* dest, const char *src)
// 功能为拷贝字符串内容到目的串，把src所指向的内容拷贝到dest
// char *strncpy(char *dest, const char *src ,int n);  // copy n strings to dest from src, NOTE:NULL

// strlen()  
// 此函数原型为unsigned in strlen(const char *str)
// 功能为返回字符串str的长度（不包括'\0')。

// strchr()  strrchr()
// char *strchr(char *str, char c)
// 功能为查找str中首次出现c的位置，如有有，则返回出现位置，否则返回NULL。实现如下：
// char *strrchr(char *str, char c)
// 功能为查找str中最后一次出现c的位置，如有有，则返回出现位置，否则返回NULL。实现如下：

// strcspn()  strspn()
// strcspn
// 原型：size_t strcspn(const char *pstr, const char *strCharset)
// MSDN解释为：在字符串pstr中搜寻strCharsret中所出现的字符，返回strCharset中出现的第一个字符在pstr中的出现位置。简单的说，若strcspn返回的数值为n，则代表字符串strCharsrt开头连续有n个字符不包含在pstr内的字符。
// 实现十分巧妙，在http://blog.csdn.net/chenyu2202863/article/details/5293941
// 原型size_t strspn(const char *pstr, const char *strCharset)

// strdup()
// 此函数原型为char *strdup(const char *str)
// 功能为拷贝字符串到新建的内存，返回内存指针。若失败，返回NULL。要注意，返回的指针指向的内存在堆中，所以要手动释放。

// strrev()
// 此函数的原型为char *strrev(char *str)
// 功能为反转字符串，返回字符串指针。

// strstr()
// 函数原型为char *strstr(const char str1, const char *str2)
// 功能为查找字符串str2在str1中出现的位置，找到则返回位置，否则返回NULL 。




// sizeof()
//定义函数：char * strdup(const char *s);
//函数说明：strdup()会先用maolloc()配置与参数s 字符串相同的空间大小，然后将参数s 字符串的内容复制到该内存地址，然后把该地址返回。该地址最后可以利用free()来释放。

// 定义函数：char * index(const char *s, int c);
// 函数说明：index()用来找出参数s 字符串中第一个出现的参数c 地址，然后将该字符出现的地址返回。字符串结束字符(NULL)也视为字符串一部分。
// 返回值：如果找到指定的字符则返回该字符所在地址，否则返回0.

// 定义函数：char * rindex(const char *s, int c);
// 函数说明：rindex()用来找出参数s 字符串中最后一个出现的参数c 地址，然后将该字符出现的地址返回。字符串结束字符(NULL)也视为字符串一部分。
// 返回值：如果找到指定的字符则返回该字符所在的地址，否则返回0。

// itoa()/sprintf  这个其实是C/C++非标准库中的函数，而是Windows平台下扩展的，标准库中有sprintf（注意是标准库），功能比这个强的多的啦，用法跟printf有点神似：
// atoi()
// memset()
// memcopy()
// void *memcpy(void *str1, const void *str2, size_t n)
// 参数
// str1 -- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针。
// str2 -- 指向要复制的数据源，类型强制转换为 void* 指针。
// n -- 要被复制的字节数。
// https://www.runoob.com/cprogramming/c-standard-library-string-h.html

//fscanf 函数原型为 int fscanf(FILE * stream, const char * format, [argument...]); 
//其功能为根据数据格式(format)，从输入流(stream)中读入数据，存储到argument中，遇到空格和换行时结束。fscanf位于C标准库头文件<stdio.h>中。 [1]



// sscanf函数原型为：
//     int sscanf(const char *buffer , const char *format , [argument ]...);
// 参数说明：
//     buffer 为存储的数据
//     format 为格式控制字符串
//     argument 选择性设定字符串
// 函数功能：
//     从一个字符串中读进与指定格式相符的数据的函数，即sscanf会从buffer里读取数据，依照format的格式将数据写入到argument里




int main(int argc ,char **argy)
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
        printf("strlen(str_1)=%ld\n",strlen(str_1));
        printf("strlen(str_2)=%ld\n",strlen(str_2));
        printf("strlen(str_3)=%ld\n",strlen(str_3));
    }
    else if(0==strcmp(argy[1], "strdup")){
        char a[] = "strdup";
        char *b;
        b = strdup(a);
        printf("b[]=\"%s\"\n", b);
    }
    else if(0==strcmp(argy[1], "atoi")){
        int n;
        char *str = "-12345.67";
        n = atoi(str);
        printf("str:%s,n=%d\n",str,n);
        return 0;
    }
    else if(0==strcmp(argy[1], "sprintf")){
        double number = -12345678.9;
        int number_1 = 12;
        char string[25];
        sprintf(string,"%lf,0x%x",number, number_1);
        printf("double=%lf,int=%d string=%s\n", number, number_1, string);
        return 0;
    }
    else if(0==strcmp(argy[1], "sscanf")){
        int number_1, number_2;
        char str_1[] = "0xac34";
        char str_2[] = "ac34";
        sscanf(str_1,"%x",&number_1);
        sscanf(str_2,"%x",&number_2);
        printf("number_1=%d ,str_1=%s,number_2=%d ,str_2=%s\n", number_1, str_1, number_2, str_2);
        return 0;
    }
    else{
        printf("para is err\n");
    }



}

