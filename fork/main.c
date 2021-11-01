#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("argc=%d , argv=%s",argc,argv[1]);

    int pid=0;
    pid = fork();
	if (pid < 0)
		printf("fork failed\n");
	else if (pid > 0) {
		printf("parent process: pid = %d\n", pid);
		wait(NULL);
	} else {
		printf("child process: pid = %d\n", pid);
		// execlp("./fcntl", "./fcntl", buffer, (char *)0);
	}

}