#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

long time_sec[100];
long time_usec[100];
struct timeval tv;
int i=0;

void timer_handler (int signum)
{
    i++;
    gettimeofday(&tv,NULL);
    time_sec[i]=tv.tv_sec;
    time_usec[i]=tv.tv_usec;
}

int main ()
{
    printf("ok");
    struct sigaction sa;
    struct itimerval timer;

    /* Install timer_handler as the signal handler for SIGVTALRM. */
    memset(&sa, 0, sizeof (sa));
    sa.sa_handler = &timer_handler;
    sigaction (SIGVTALRM, &sa, NULL);

    /* Configure the timer to expire after 100 msec... */
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec =250;
    /* ... and every 100 msec after that. */
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec =250;
    /* Start a virtual timer. It counts down whenever this process is
    executing. */

    setitimer (ITIMER_VIRTUAL, &timer, NULL);

    /* Do busy work. */
    while(1)
    {
	    if( i==99)
		    break;
    }
    for(int j=1;j<100;j++ )
    {
	    printf( "usec=%ld\n",time_usec[j]-time_usec[j-1]);
    }
    return 0;
}

