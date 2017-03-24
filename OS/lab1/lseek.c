#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

main()
{	int fd;
	fd=creat("name2.txt",0775);
	fd=open("name2.txt",O_RDWR,0);
	if(fd<=-1)
	printf("\nFile can't open");
	char arr[60]; 
	 if(read(fd,arr,5) != 5)  return 1;
        printf("%s\n",arr);
        lseek(fd,4,SEEK_SET);
	read(fd,arr,5);
	printf("%s\n",arr);
}
