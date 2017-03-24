#include<stdio.h>
void sort();
int a[20],n;
main()
{	int head,prev,i,seek=0,c=0;
	printf("\nEnter head and prev Values:");
	scanf("%d %d",&head,&prev);
	printf("\nEnter number of requests:");
	scanf("%d",&n);
	printf("\nEnter Request Times :");
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);
	}
	if(head>prev)
	{	sort();
		seek=a[n-1]-head;
		for(i=0;i<n;i++)
		{	if(head>a[i])
				c++;
			else
				break;
		}
			seek+=a[n-1]-a[c-1];
			c--;
		while(c!=0)
		{	seek+=a[c]-a[c-1];
			c--;
		}		
	}
	else
	{	sort();
		seek=a[0]-head;
		for(i=0;i<n;i++)
		{	if(head<a[i])
				c++;
			else
				break;
		}
		seek+=a[0]-a[c-1];
		c--;
		while(c!=0)
		{	seek+=abs(a[c+1]-a[c]);
			c--;
		}
	}
	printf("\nTotal Seek Time :%d\n",seek);
}
void sort()
{	int i,j,temp;
	for(i=0;i<n-1;i++)
	{	for(j=0;j<n-1-i;j++)
		{	if(a[j]>a[j+1])
			{	temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}
