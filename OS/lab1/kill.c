#include<stdio.h>
#include<stdlib.h>
 #include <sys/types.h>
  #include <signal.h>
main()
{
       int id,sig;
	pid_t pid; 
		id=kill(pid,sig);
	printf("\nAfter KILL System Call: %d\n",id);
}


