#include <stdio.h>
int a[20],d;
void enq(int x)
{	int i,j,g=0;
	for(i=0;a[i]!=-1;i++)
	{	if(a[i]==x)
		{	for(j=i;a[j]!=-1;j++)
			{	a[j]=a[j+1];
			}
			a[j]=x;
			g=1;
			break;	
		}
	}
	if(g==0)
	{	a[i]=x;
	}
}
int deq()
{	int x=a[0],i;
	for(i=0;a[i]!=-1;i++)
	{	a[i]=a[i+1];
	}
	return x;
}
void main()
{	int n,p[20],i,j,hit=0,miss=0,g=0;
	printf("\nEnter Number of Frames : ");
	scanf("%d",&d);
	printf("\nEnter number of Pages Requests :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	printf("\nEnter Page Number-%d : ",i+1);
		scanf("%d",&p[i]);
		if(i<d+1)
		a[i]=-1;
	} 	
	for(i=0;i<n;i++)
	{	g=0;
		if(a[i]==-1)
		{	miss++;
			a[i]=p[i];
			enq(i);
		}
		else 
		{	for(j=0;j<3;j++)
			{	if(a[j]==p[i])
				{	hit++;
					enq(j);
					g=1;
					break;
				}
			}
			if(g==0)
			{	a[deq()]=p[i];
				miss++;
			}
		}	
	}
	printf("\nTotal Hit : %d ",hit);
	printf("\nTotal Miss : %d ",miss);
	}
