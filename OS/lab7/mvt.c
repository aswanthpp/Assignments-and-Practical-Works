
#include<stdio.h>
main()
{	int mem_size,os_size,n,s[10],i;
	printf("\nEnter Total Disk Space:");
	scanf("%d",&mem_size);
	printf("\nEnter OS Size:");
	scanf("%d",&os_size);
	printf("\nEnter Number of Process :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	printf("\nEnter Size of Process-%d : ",i+1);
		scanf("%d",&s[i]);
	}
	mem_size-=os_size;
	for(i=0;i<n;i++)
	{	if(mem_size>s[i])
		{	printf("\nProcess-%d allocated ",i+1);
			mem_size-=s[i];
		}
		else
		{	printf("\nProcess-%d is Not Allocated due to insuffient Memory ",i+1);
		}
	}
	printf("\nTotal Size of holes in Memory : %d \n",mem_size);
}			

