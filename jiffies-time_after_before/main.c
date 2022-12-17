#include<stdio.h>
#include<unistd.h>
#include  <linux/sockios.h>
#include  <linux/ethtool.h>
#include <linux/jiffies.h>


int main(int arg, char **args)
{
    printf("jiffies = %d",jiffies);

}

//      *  time_after：
//      *  time_after(a,b) returns true if the time a is after time b.
<<<<<<< HEAD
// 　　同时根据 #define time_before(a,b)    time_after(b,a) ，我们可以知道  

//      * time_before(a,b) returns true if the time b is after time a.
//      jiffies(linux-滴答时钟)
=======
// // 　　同时根据 #define time_before(a,b)    time_after(b,a) ，我们可以知道  

//      * time_before(a,b) returns true if the time b is after time a.
>>>>>>> 2451533ab5a0d6c09bac9ad3280975645bddb541
