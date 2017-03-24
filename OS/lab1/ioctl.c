#include <sys/ioctl.h>
#include<stdio.h>
#include<unistd.h>
main()
{		int rvalue,fd;
		unsigned long int x=7869560;

      rvalue=ioctl(fd, x);
	if(rvalue<0)
	{	printf("\nError");
	}
	else
	{	printf("\nSystemcall ioctl sucessfull");
	}
	printf("\n");
}
