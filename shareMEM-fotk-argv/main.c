#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/shm.h>


#include <wait.h>

#define PERM S_IRUSR|S_IWUSR
//share mem


int main(int argc, char **argy)
{
    int shmid;
    char *p_addr,*c_addr;


    printf("TEST argc=%d \n",argc);
    printf("TEST argy=%s\n",argy[1]); //second parameter ->argy[1]
    if(argc!=2)
    {
        fprintf(stderr,"Usage:%s\n\a",argy[0]);
        exit(0);
    }


    //create mem
    if((shmid=shmget(IPC_PRIVATE,1024,PERM))==-1)
    {
        fprintf(stderr,"Usage:%s\n\a",argy[0]);
        exit(0);
    }
    //main process
    if(fork())
    {
        p_addr=shmat(shmid,0,0);
        memset(p_addr,"\0",1024);
        strncpy(p_addr,argy[1],1024);
        printf("main process wait() begin\n");
        wait(NULL);//wair subprocess exit;
        printf("main process wait() over \n");
       // exit(0);  //will break mainprocess
    }
    else //subprocess
    {
        sleep(1);
        c_addr=shmat(shmid,0,0);
        printf("Client get %s \n",c_addr);
        printf("subprocess sleep begin\n");
        sleep(10);
        printf("subprocess sleep over\n");
        //exit(0);////will break subprocess
    }
    printf("main over\n");
}