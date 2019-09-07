#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
long flag=0;

void myinterruptservice()
{
	flag++;
	printf("Enter interrupt!\n");

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
	}
}

