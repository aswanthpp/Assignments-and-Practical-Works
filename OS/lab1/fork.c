#include<stdio.h>
#include<unistd.h>
main()
{	int pid;
	printf("Before fork function called\n");
	pid=fork();
	printf("After Fork function called\n");
}
