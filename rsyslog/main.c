#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
 
int main()
{
 
    // openlog("msg-lyh", LOG_PID, LOG_LOCAL0);
    syslog(LOG_INFO, "this is a test");
 
 
    // closelog();
 
    return 0;

}
