#include <sys/time.h>
#include <time.h>
#include <stdio.h>

int main()
{
	struct timeval tv;
	struct timeval t2;
	tv.tv_sec=0x1000000;
	tv.tv_usec=0;
	t2.tv_sec=0x100000d;
	t2.tv_usec=0x993f3;
	if(settimeofday(&tv,NULL)==-1)
	{
		printf("fail\n");
	}
	//gettimeofday(&t2,NULL);
	sleep(1);
	settimeofday(&t2,NULL);
	printf("%ld\n",t2.tv_sec);
	printf("%ld\n",t2.tv_usec);
}
