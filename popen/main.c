#include <stdio.h>
int main(int argc, char *argv[])
{
    char buf[128];
    FILE *pp;
    if( (pp = popen("ls -l", "r")) == NULL )
    {
        printf("popen() error!\n");
        exit(1);
    }
    while(fgets(buf, sizeof buf, pp))
    {
        printf("%s", buf);
    }
    pclose(pp);
    return 0;
}