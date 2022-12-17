#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
    time_t ctime;
    struct tm *tm;
    char *stime;
    
    ctime = time(NULL);//返回日历时间
    printf("ctime = %d\n",ctime);

    tm = gmtime(&ctime);//将日历时间转换为标准时间。
    printf("UTC: year+1900 =%d,mon+1 = %d,day = %d,hour = %d,min = %d,sec = %d\n",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min,tm->tm_sec);

    tm = localtime(&ctime);//将日历时间转换为本地时间。
    printf("local time: year+1900 =%d,mon+1 = %d,day = %d,hour = %d,min = %d,sec = %d\n",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min,tm->tm_sec);

    stime = asctime(tm);//将时间转换为字符串
    printf("localtiem : %s\n",stime);



    struct timeval tv;
    gettimeofday(&tv,NULL); //获取秒和微妙
    printf("time: s =%d,us = %d\n",tv.tv_sec,tv.tv_usec);
    sleep(1);
    gettimeofday(&tv,NULL); //获取秒和微妙
    printf("time: s =%d,us = %d\n",tv.tv_sec,tv.tv_usec);
    usleep(1000);
    gettimeofday(&tv,NULL); //获取秒和微妙
    printf("time: s =%d,us = %d\n",tv.tv_sec,tv.tv_usec);


    return 0;
} 