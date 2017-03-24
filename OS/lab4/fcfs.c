#include<stdio.h>
main()
{	int head,prev,a[20],i,n,seektime=0;
	printf("\nEnter head and prev Values:");
	scanf("%d %d",&head,&prev);
	printf("\nEnter number of requestes:");
	scanf("%d",&n);
	printf("\nEnter Request Times:");
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);
	}
	seektime=abs(head-a[0]);
	for(i=0;i<n-1;i++)
	{	seektime+=abs(a[i+1]-a[i]);
	}
	printf("\nTotal Seek Time:%d\n",seektime);
}

