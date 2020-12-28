#include <stdio.h>
#include <stdlib.h>

int firstUniqChar(char * s){
    int arr[256] = {0};    //创建数组
    char *p = s;            //保存字符串首地址
    int r = -1;
    while(*p != '\0')    //单次循环记录每个字符出现的次数
    {
        printf("*p=%d\n",*p);
        arr[*p]++;
        p++;
    }
    p = s;
    while(*p != '\0')    //根据字符出现的顺序，遍历出第一个符合要求的字符
    {
        printf("*p2=%d\n",*p);
        if(arr[*p]==2)
        {
            r = p-s;     //得到改字符的下标
            break;
        }
        p++;
    }
    return r;
}

int main(int arg, char **argv)
{
    int offset;
    if(arg!=2)
    {
        printf("parmater only need 1 \n");
        exit(0);
    }
    printf("argv=%s\n",argv[1]);
    offset=firstUniqChar(argv[1]);
    printf("offset=%d\n",offset);
}