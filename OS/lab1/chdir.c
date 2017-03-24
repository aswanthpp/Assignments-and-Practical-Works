#include<stdio.h>
 #include <unistd.h>
main()
{	int rvalue;
	char a[]={"/os/lab2"};
       rvalue=chdir(a);
	if(rvalue<0)
	{	printf("\nError in Changing Path");
	}
	else
	{	printf("\nPath changed Sucessfully");
	}
	printf("\n");
}
