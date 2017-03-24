#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
main()
{	int test;
	test=access("name1.txt",F_OK);
	printf("Test value = %d\n",test);
}
