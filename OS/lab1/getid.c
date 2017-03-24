#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>


main()
{	pid_t my_pid,parent_pid,user_id,effective_uid,group_id,effective_gid;
	my_pid=getpid();
	parent_pid=getppid();
	user_id=getuid();
	effective_uid=geteuid();
	group_id=getgid();
	effective_gid=getegid();

	printf("\nChild PID= %d",my_pid);
	printf("\nParent PID = %d",parent_pid);
	printf("\nUser ID = %d",user_id);
	printf("\nEffective User ID = %d ",effective_uid);
	printf("\nGroup ID = %d",group_id);
	printf("\nEffective Group ID = %d",effective_gid);
	printf("\n");

	
}
