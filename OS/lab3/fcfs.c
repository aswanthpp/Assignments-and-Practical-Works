#include<stdio.h>
int main()
{
    int n,bt[20],wt[20],tat[20],at[20],ct[20],i,j;
    printf("Enter number of processes:");
    scanf("%d",&n);
    printf("\nEnter Process Arrival time:");
    for(i=0;i<n;i++)
       scanf("%d",&at[i]);
    printf("\nEnter Process Burst Time:");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);
    wt[0]=0;    
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("\nProcess\t\tBurst Time\tC Time\t\tTA Time\t\tWait Time");
 
    
    for(i=0;i<n;i++)
    {
        ct[i]=bt[i]+wt[i];
	tat[i]=ct[i]-at[i];
	wt[i]=tat[i]-bt[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],ct[i],tat[i],wt[i]);
    }
	printf("\n");
    return 0;
}
