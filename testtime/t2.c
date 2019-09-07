#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <error.h>
#include <time.h>

struct timeval tv;
long time_sec[100];
long time_usec[100];
int flag=0;
void handle()  

{  

    flag++;
    gettimeofday(&tv,NULL);  
    time_sec[flag]=tv.tv_sec;
    time_usec[flag]=tv.tv_usec;
}  
int main()  
{  
    struct sigevent evp;  
    struct itimerspec ts;  

    timer_t timer;  

    int ret;  
    evp.sigev_value.sival_ptr = &timer;  
    evp.sigev_notify = SIGEV_SIGNAL;  
    evp.sigev_signo = SIGUSR1;  
    signal(SIGUSR1, handle);  
  
    ret = timer_create(CLOCK_REALTIME, &evp, &timer);  
    if( ret )  
        perror("timer_create");  
  
    ts.it_interval.tv_sec = 0;  
    ts.it_interval.tv_nsec = 1250000;  
    ts.it_value.tv_sec = 0;  
    ts.it_value.tv_nsec =1250000;  
  
    ret = timer_settime(timer, 0, &ts, NULL);  
    if( ret )  
    perror("timer_settime");  

    while(1)  
    {
	    if (flag==99)
		    break;
    }
    for (int j=1;j<100;j++)
    {
    printf("sec=%ld,use=%ld\n",time_sec[j],time_usec[j]-time_usec[j-1]);
    }
}
