#include<stdio.h>
#include<unistd.h>
main()
{	int pid;
	printf("\nBefore Wait Function Call\n");
	pid=wait();
	printf("\nAfter wait function call\n");
}

