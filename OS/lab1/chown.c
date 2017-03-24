#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
main()
{	int p=chown("name.txt",1845,1847);
	printf("%d\n",p);
}
