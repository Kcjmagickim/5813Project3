/**********************************
@file: mymem.c
@brief: profiles my_memmove and my_memset functions
@author: John Kim
@date: Apr 4th, 2018
***********************************/

#include <stdlib.h>
#include <string.h>
#include "memory.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

int main(int argc,char* argv[])
{
	char c[50] = "Number of bytes Transferred: ";
	char c2[50] = "Number of bytes Set: ";
	char b[50] = "Time in nano seconds: ";
	char a[50] = "Stack usage: ";
	char d[50] = "bytes";
    char buf[50];
	struct timespec tstart={0,0}, tend={0,0};	
	//clock_t stop, start;
	uint32_t ns, SIZE;
	int stack = 0, q;
	
	if (argc==1) SIZE=10;
	else if (argc==2) SIZE=100;
	else if (argc==3) SIZE=1000;
	else SIZE=5000;

	uint8_t * fill = (uint8_t *) malloc(SIZE);
	uint8_t * src = (uint8_t *) malloc(SIZE);

	//uint32_t factor = 1000000000 / CLOCKS_PER_SEC;
	
	//start=clock();
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	my_memset(fill, SIZE, 0xff);
	//stop=clock();
	clock_gettime(CLOCK_MONOTONIC, &tend);
	//ns = ((uint32_t) (stop - start))*factor;
	ns = tend.tv_nsec - tstart.tv_nsec;

	printf("%s%d\n", c2, SIZE);	//profile memset
	printf("%s%d\n", b, (int) ns);

	//start=clock();
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	my_memmove(src, fill, SIZE);
	//stop=clock();
	clock_gettime(CLOCK_MONOTONIC, &tend);
	//ns = ((uint32_t) (stop - start))*factor;
	ns = tend.tv_nsec - tstart.tv_nsec;

	printf("%s%d\n", c, SIZE);	//profile memmove
	printf("%s%d\n", b, (int) ns);

	FILE *fp = fopen("mymem.su","r");
	if (!fp){}
	else{
			q=fscanf(fp, "%s", buf);
			q=fscanf(fp, "%s", buf);
			stack = atoi(buf);
   	}
   	
   	fp = fopen("memory.su","r");
	if (!fp){}
	else{
			q=fscanf(fp, "%s", buf);
			q=fscanf(fp, "%s", buf);
			stack += atoi(buf);
   	}
 	if(q){}  	
	printf("%s%d %s\n",a, stack, d);
    return 0;
}
