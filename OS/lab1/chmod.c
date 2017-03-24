#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{	int p=chmod("name.txt",S_IWUSR);
	printf("%d\n",p);
}
