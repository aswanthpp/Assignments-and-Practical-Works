#include<stdio.h>
main()
{	int n,s[10],i,j,mem_size=0,a,IF=0,EF=0,flag[10];
	int free,p,f=0;
	printf("\nEnter number of memory Sections : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	printf("\nEnetr Size of Section-%d : ",i+1);
		scanf("%d",&s[i]);
		flag[i]=0;
		mem_size+=s[i];
	}
	for(i=0;i<n-1;i++)
	{	for(j=0;j<n-i-1;j++)
		{	if(s[j]<s[j+1])
			{	f=s[j];
				s[j]=s[j+1];
				s[j+1]=f;
			}
		}
	}
	free=mem_size;
	printf("\nTotal Memory Size :%d ",mem_size);
	printf("\nEnter number of Process:");
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{	printf("\nEnter size of Process-%d : ",i+1);
		scanf("%d",&a);
		f=0;
		for(j=0;j<n;j++)
		{	
			if((s[j]>=a)&&(flag[j]==0))
			{	
				printf("\nProcess-%d is allocated ",i+1);
				f=1;
				printf("\tInternal Fragmentation : %d ",(s[j]-a));
				IF+=s[j]-a;
				flag[j]=1;
				free-=s[j];
				goto xx;
			}
		
		}		
		xx:if(f==0)
		{
		printf("\nProcess-%d is not Allocated",i+1);	
		}
			
	}
	printf("\n\n\nExternal Fragmentation : %d ",free);
	printf("\nInternal Fragmentation :%d \n",IF);
	}
