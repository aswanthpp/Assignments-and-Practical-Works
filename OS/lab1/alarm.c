#include <unistd.h>
#include<stdio.h>
main()
{	

	int seconds=1,rvalue;
       rvalue=alarm(seconds);
	printf("\nRetrun Value of alarm System Call= %d\n",rvalue);
}
