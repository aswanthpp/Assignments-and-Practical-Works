nclude<unistd.h>
#include<fcntl.h>
#include<stdio.h>

main()
{	int fd;
	fd=open("name.txt",O_RDWR,0);
	int new_fd=dup(fd);
	printf("\nNEW FD VALUE :%d\n",new_fd);
close(fd);
}
