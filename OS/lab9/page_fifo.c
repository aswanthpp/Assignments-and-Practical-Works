#include<stdio.h>
main()
{	int n,a[10],p[20],i,j,hit=0,miss=0,f=0,g=0,d;
	printf("\nEnter number of Frames :");
	scanf("%d",&d);
	printf("\nEnter number of Pages : ");
	scanf("%d",&n);
	for(i=0;i<d;i++)
	{	a[i]=-1;
	}
	for(i=0;i<n;i++)
	{	
		printf("\nEnter Page number-%d : ",i+1);
		scanf("%d",&p[i]);
	
	}
	for(i=0,f=0;i<n;i++)
	{	g=0;
		if(a[f]==-1)
		{	a[f]=p[i];
			f=(f+1)%d;
			miss++;
		}
		else
		{
			for(j=0;j<d;j++)
			{	if(a[j]==p[i])
				{	hit++;
					g=1;
					break;
				}
			}
			if(g==0)
			{	a[f]=p[i];
				f=(f+1)%d;
				miss++;
			}
		}
		for(j=0;j<d;j++)
		{	printf("%d ",a[j]);
		}
		printf("\n");

	}
	printf("\nTotal Hit= %d\n",hit);
	printf("\nTotal Miss = %d \n",miss);
	
/*	for(i=0;i<n;i++)
	{	for(j=0;j<3;j++)
		{	printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
	printf("\n");


}
				
	
