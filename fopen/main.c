
#include <stdio.h>


#define SSIZE_MAX 10 
int main(int argc, char **argv)
{    

    FILE *fd = NULL; 
    char key_val[10] ;
	printf("***********************\nfopen  test \nTime:2020.04.20\n\n\n");
	

	fd = fopen("file-1","a+"); //note: fd is FILE
    if (fd < 0)  
    {  
        printf("can't open!\n");  
        return -1;  
    }

    while (1)  
    {  
        //parameter1 read head parameter2 read element parameter3 read n element parameter4 read file
        int readCount = fread(key_val,sizeof(key_val),4,fd);
        if(feof(fd)) //confirm fd is end
        {
            printf("We have reached the end of file\n");
            printf("Readcount=%d\n",readCount); 
            printf("ReadDate: %s\n",key_val);  
            break;
        }
            
        printf("Readcount=%d\n",readCount); 
        printf("ReadDate: %s\n",key_val);  
        sleep(2);
    }  

    fclose(fd);
    return 0;
}
