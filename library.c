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
	clock_t stop, start;
	uint32_t ns, SIZE;
	int stack;
	
	if (argc==1) SIZE=10;
	else if (argc==2) SIZE=100;
	else if (argc==3) SIZE=1000;
	else SIZE=5000;
	
	uint8_t * fill = (uint8_t *) malloc(SIZE);
	uint8_t * src = (uint8_t *) malloc(SIZE);

	uint32_t factor = 1000000000 / CLOCKS_PER_SEC;

	//my_memmove(&fill[20], (uint8_t *) DESTINATION_ADDRESS, SIZE);
	start=clock();
	memset(fill, 0xff, SIZE);
	stop=clock();
	ns = ((uint32_t) (stop - start))*factor;

	printf("%s%d\n", c, SIZE);	//profile memmove
	printf("%s%d\n", b, (int) ns);

	start=clock();
	memmove (fill, src, SIZE);
	stop=clock();
	ns = ((uint32_t) (stop - start))*factor;

	printf("%s%d\n", c2, SIZE);	//profile memset
	printf("%s%d\n", b, (int) ns);

	FILE *fp = fopen("library.su","r");
	if (!fp){}
	else{
			fscanf(fp, "%s", buf);
			fscanf(fp, "%s", buf);
			stack = atoi(buf);
   	}
   	
   	fp = fopen("memory.su","r");
	if (!fp){}
	else{
			fscanf(fp, "%s", buf);
			fscanf(fp, "%s", buf);
			stack += atoi(buf);
   	}
   	
	printf("%s%d %s\n",a, stack, d);
    return 0;
}
