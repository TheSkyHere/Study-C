#include "stdio.h"
#include "stdlib.h"
//by sky

// int main(){
//     __uint8_t cnt_l,cnt_h;
//     int cnt;
//     cnt_l = 0x12;
//     cnt_h = 0x12;
//     // cnt = cnt_h<<8;
//     // cnt = (cnt_h<<8) + cnt_l;
//     printf("0x%x \n",((cnt_h<<8) + cnt_l));


//     cnt_l = 0xff;
//     printf("0x%x \n",cnt_l);

//     cnt_l = 0xff;
//     cnt_l += 1;
//     printf("0x%x \n",cnt_l);
// }

// int main(void)
// {
//     int n;
//     char *str = "e1";
//     n = atoi(str);
//     printf("n=%d\n",n);
//     return 0;
// }
#define BF_PORT_LED_NUM_AT_BYTE  4

// int main()
// {
//     char   szValue[]  =   "0x1e";   
//     int    nValude    =   0;       
//     sscanf(szValue,"%x",&nValude);   
//     printf("%d\n",nValude);
//     printf("%d\n",(17%16));
//     return 0; 
// }


int main()
<<<<<<< HEAD
{
    int i ;
    for(i = 0;i<BF_PORT_LED_NUM_AT_BYTE;i++){
        printf("\n");
    }
    return 0; 
}
=======
{    
    char buf[100];
    int len;
    int len_1;
    int x = 101;
    x=30/9;
    printf("%d\n",x);
}
>>>>>>> 2451533ab5a0d6c09bac9ad3280975645bddb541
