#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

#include <signal.h>
main()
{

	typedef void (*sighandler_t)(int);
	int signum;
	sighandler_t handler;
	sighandler_t signal(signum,handler);
}
