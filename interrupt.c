#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
struct timeval tv;
long flag=0;
long timesec[16005];
long timeusec[16005];

void myinterruptservice()
{
	flag++;
	gettimeofday(&tv,NULL);
	timesec[flag]=tv.tv_sec;
	timeusec[flag]=tv.tv_usec;

}


int main()
{
	if(wiringPiSetup()<0)
	{
		printf("can't init wiringPi\n");
		return -1;
	}
	pinMode(0,INPUT);
	pullUpDnControl(0,PUD_DOWN);

	if(wiringPiISR(0,INT_EDGE_RISING,&myinterruptservice)<0)
	{
		printf("unable registered customize interrupt service function");
	}
	while(1)
	{
		if (flag==22)
			break;
	}
	for(int j=1;j<=20;j++)
	{
		printf("time sec %d, usec %d\n",timesec[j],timeusec[j]-timeusec[j-1]);
	}
}

