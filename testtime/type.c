#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

int main()
{



	struct timeval tv;
	printf("long long int %d\n",sizeof(long long int));
	printf("tv_sec %d\n ",sizeof(tv.tv_sec));
	printf("tv_usec %d\n",sizeof(tv.tv_usec));
	gettimeofday(&tv,NULL);
	printf("tv_sec %x\n",tv.tv_sec);
	printf("tv_usec %x\n",tv.tv_usec);
}
