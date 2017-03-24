#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
main()
{	char a[5];
	int p,i;
	p=open("name.txt",O_RDWR,0);
	read(p,a,5);
	printf("%s\n",a);
	close(p);
}
