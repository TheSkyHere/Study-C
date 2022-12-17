#include <stdio.h>
//by sky

#define SSIZE_MAX 10 
int main(int argc, char **argv)
{    

    FILE *fd = NULL; 
    char key_val[10] ;
	printf("***********************\nfopen  test \nTime:2020.04.20\n\n\n");
	

	fd = fopen("/home_a/matao/workspace/Study/Study-C/fopen()/file-1","a+"); //note: fd is FILE
    if (fd < 0)  
    {  
        printf("can't open!  <0 \n");  
        return -1;  
    }
    if (fd > 0)  
    {  
        printf("can't open!  > 0\n");  
        return -1;  
    }
    if (fd == 0)  
    {  
        printf("can't open!  = 0\n");  
        return -1;  
    }
    printf("test ok!\n");  
    fclose(fd);
    return 0;
}
