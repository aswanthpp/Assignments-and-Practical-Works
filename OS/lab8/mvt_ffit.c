#include<stdio.h>
main()
{	int n,s[10],i,mem_size=0,j,flag[10],f,p,a;
	printf("\nEnter Number of Partions :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	printf("\nEnter size of Partion-%d : ",i+1);
		scanf("%d",&s[i]);
		mem_size+=s[i];
		flag[i]=0;
	}
	printf("\nEnter number of process : ");
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{	printf("\nEnter Size of Process-%d : ",i+1);
		scanf("%d",&a);
		f=0;
		for(j=0;j<n;j++)
		{
			if(s[j]>=a&&flag[j]==0)
			{	printf("\nProcess-%d is Allocated ",i+1);
				f=1;
				s[j]=s[j]-a;
				mem_size-=a;
				if(s[j]==0)
				{	flag[j]=1;
				}
				goto xx;
			}
		}	
		xx: if(f==0)
		{	printf("\nProcess-%d is not Allocated",i+1);
		}
	}
	printf("\nExternal Fragmentation : %d \n",mem_size);
	}

