#include<stdio.h>
void sort();
int a[20],n;
main()
{	int head,prev,i,limit,seek=0,f=0;
	printf("\nEnter head and Prev Values:");
	scanf("%d %d",&head,&prev);
	a[0]=head;
	printf("\nEnter Total Cylinders:");
	scanf("%d",&limit);
	limit-=1;
	printf("\nEnter Number of Requests:");
	scanf("%d",&n);
	printf("\nEnter Requests :");
	for(i=1;i<=n;i++)
	{	scanf("%d",&a[i]);
	}
	 if(head>prev)
        {       sort();
		for(i=0;i<=n;i++)
		{	if(a[i]==head)
				f=i;
		}
		seek=limit-a[0];
		seek+=limit-a[f];  
		for(i=0;i<f-1;i++)
			seek+=a[i+1]-a[i];
		

    	}
	else
	{	printf("\nDisk Rotation inside to outside\n");
		return 0;
	}
	
	printf("\nTotal Seek Time :%d\n",seek);
}
void sort()
{	int i,j,temp;
	for(i=0;i<n;i++)
	{	for(j=0;j<n-i;j++)
		{	if(a[j]>a[j+1])
			{	temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
