#include<stdio.h>
#include<string.h>

typedef void (*fun_1)(void);
typedef int* (*fun_2)(int*,int);


typedef struct STR
{
    int num;
    int type;
    fun_1 fu1;
    fun_2 fu2;
}Stu,*Stu1;      //注意Stu*和Stu1等价！！！！




void fun1(void)
{
    printf("I am fun1\r\n");
}

char table1[]="this is table1";

int * fun2(int*p,int x)
{
    char table[]="this is table";
  //  sprintf(table,"this is ");
    if(x==1)
    {
        printf("I am fun2 x==1\r\n");
    }
    else
    {
        printf("I am fun2 x==2\r\n");
    }
    printf("input =%s \r\n",p);
  //  stract(table,p);
    // return table;    //Error "table" will dele after fun2  
    return (int*)table1;  //ok   "table1" not dele after fun2 
}




void main()
{
    Stu1 stu;
    Stu struct_1 = {3, 4, fun1, fun2};  //等同于 type 1
    stu=&struct_1;    //注意关于结构体指针的赋值！！！！！  pointer need entity


    // struct_1.fun1=fun3;
    // struct_1.fun2=fun4;
    printf("starting_begin\r\n");


    //type 1
    stu->num=3;
    stu->type=4;
    stu->fu1 =fun1;     //注意函数指针的赋值
    stu->fu2 =fun2;     //注意函数指针的赋值

    printf("starting\r\n");
    int table[10];
    int *p1;
    int *p ="test";



    // table = "1234";

    (*(stu->fu1))();
    p1 = (*(stu->fu2))(p,1);
   

    // // stu=&struct_1;   //注意关于结构体指针的赋值！！！！！


    // // (*(stu->fu1))();
    // // table = (*(stu->fu2))(p,1);


    printf("num=%d,type=%d,end=%s \n",stu->num,stu->type,p1);


}


// char table[][]
// {
//     1,fun1;
//     2,main;
//     3,SSSS;
// }