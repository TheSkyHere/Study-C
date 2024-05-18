#include "stdio.h"
#include "stdlib.h"


int main()
{
    char buffer[32]; 
    char log_flag = 0;
    FILE* fd = fopen("./123.test", "r"); 
    if (fd != NULL) {
        log_flag=0;
        fgets(buffer, sizeof(buffer), fd);
        fclose(fd);
        if(0 == strncmp(buffer, "0x1", strlen("0x1"))) //0x1 is power ok
        {
            printf("001:-1");
            return 0;   //power on
        }
        else{
            printf( "002:-1");
            return -1;   //power off
        }
    }
    else{
        if(!log_flag){
            printf( "[%s] open %s failed", __func__, "./123.test");
            log_flag=1;
        }
    }
    printf( "003:-1");
    return -1;
}