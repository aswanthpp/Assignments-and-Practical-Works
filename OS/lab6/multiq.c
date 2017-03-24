#include<stdio.h>
#include<stdlib.h>
	struct node
	{
		int bt[20],wt[20],tat[20],at[20],ct[20],p[20];
	}q1,q2;
main()
{	int f,n,i,j,k,n1,n2,ta=0,sum=0,temp[20],time_quantum=2,counter=0,total=0,limit,tat,at,x,wt;
	printf("\nEnter total number of process:");
	scanf("%d",&n);
	for(i=0,j=0,k=0;i<n;i++)
	{	printf("\nSystem Process(1) User Process(0):");
		scanf("%d",&f);
		if(f==1)
		{	printf("\nEnter Arrival Time:");
			scanf("%d",&q1.at[j]);
			printf("\nEnter Burst Time:");
			scanf("%d",&q1.bt[j]);
			q1.p[j]=i;
			j++;
			
		}
		else
		{	printf("\nEnter Arrival Time:");
			scanf("%d",&q2.at[k]);
			printf("\nEnter Burst Time:");
			scanf("%d",&q2.bt[k]);
			q2.p[k]=i;
			k++;
		}
	}
	n1=j;
	n2=k;
	q1. wt[0]=q1.at[0];    
    for(i=1;i<n1;i++)
    {
        q1.wt[i]=q1.at[0];
        for(j=0;j<i;j++)
           q1. wt[i]+=q1.bt[j];
    }
	printf("\nFirst Scheduling done in FCFS Algorithm");
    printf("\nProcess\t Burst Time\t Turnaround Time\t Wait Time");
    for(i=0;i<n1;i++)
    {
        q1.ct[i]=q1.bt[i]+q1.wt[i];
        q1.tat[i]=q1.ct[i]-q1.at[i];
        q1.wt[i]=q1.tat[i]-q1.bt[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",q1.p[i]+1,q1.bt[i],q1.tat[i],q1.wt[i]);
    }

printf("\n\nSecond Scheduling is done by Round robin Fashion");
for(i=0;i<n2;i++)
{	temp[i]=q2.bt[i];
}
x=n2;
limit=n2;
 printf("\nProcess\t Burst Time\t Turnaround Time\t Wait Time");
        for(total = q1.ct[n1-1], i = 0; x != 0;)
        {
                if(temp[i] <= time_quantum && temp[i] > 0)
                {
                        total = total + temp[i];
                        temp[i] = 0;
                        counter = 1;
                }
                else if(temp[i] > 0)
                {
                        temp[i] = temp[i] - time_quantum;
                        total = total + time_quantum;
                }
                if(temp[i] == 0 && counter == 1)
                {
                        x--;
                        printf("\nP[%d]\t\t%d\t\t %d\t\t\t %d", q2.p[i] + 1, q2.bt[i], total -q2.at[i], total - q2.at[i] -q2.bt[i]);
                        wt = wt+ total - q2.at[i] - q2.bt[i];
                        tat= tat+ total - q2.at[i];
                        counter = 0;
                }
                if(i == limit - 1)
                {
                        i = 0;
                }
                else if(q2.at[i + 1] <= total)
                {
                        i++;
                }
                else
                {
                        i = 0;
                }
        }
printf("\n");

}	
