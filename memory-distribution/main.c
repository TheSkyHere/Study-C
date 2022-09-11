#include <stdio.h>
#include <stdlib.h>
int global_init_a = 1;
int global_uninit_a;
static int static_global_init_a = 1;
static int static_global_uninit_a;
const int const_global_a = 1;



int main(int argc,char **argv)
{
    int local_init_a = 1;
    int local_uninit_a;
    static int static_local_init_a = 1;
    static int static_local_uninit_a;
    const int const_local_a = 1;

    int * malloc_p_a;
    malloc_p_a = malloc(sizeof(int));

    printf("&global_init_a=%p,global_init_a=%d\n",&global_init_a,global_init_a);
    printf("&global_uninit_a=%p,global_uninit_a=%d\n",&global_uninit_a,global_uninit_a);
    printf("&static_global_init_a=%p,static_global_init_a=%d\n",&static_global_init_a,static_global_init_a);
    printf("&static_global_uninit_a=%p,static_global_uninit_a=%d\n",&static_global_uninit_a,static_global_uninit_a);
    printf("&const_global_a=%p,const_global_a=%d\n",&const_global_a,const_global_a);

    printf("&local_init_a=%p,local_init_a=%d\n",&local_init_a,local_init_a);
    printf("&local_uninit_a=%p,local_uninit_a=%d\n",&local_uninit_a,local_uninit_a);
    printf("&static_local_init_a=%p,static_local_init_a=%d\n",&static_local_init_a,static_local_init_a);
    printf("&static_local_uninit_a=%p,static_local_uninit_a=%d\n",&static_local_uninit_a,static_local_uninit_a);
    printf("&const_local_a=%p,const_local_a=%d\n",&const_local_a,const_local_a);
    printf("malloc_p_a=%p,*malloc_p_a=%d\n",malloc_p_a,*malloc_p_a);


    while(1);
    return 0;
    
}