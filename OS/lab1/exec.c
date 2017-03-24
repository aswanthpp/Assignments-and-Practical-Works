#include<stdio.h>
#include<unistd.h>

main()
{	int pid1,pid2;
	printf("Before EXECL system Call\n");
	pid1=fork();
	pid2=execl(&pid1);
	printf("After EXECL system Call");
}
