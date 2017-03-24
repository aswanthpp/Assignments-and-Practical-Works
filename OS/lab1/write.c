#include<fcntl.h>
#include<unistd.h>
main()
{	int p;
	p=open("name.txt",O_RDWR,0);
	
	int w=write(p,"Hello",5);
	close(p);
}
