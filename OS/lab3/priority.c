 
#include <stdio.h>
#include <stdlib.h>

int n, at[100], bt[100],tat=0,wt=0,pr[100],p[100],tsum=0,wsum=0;
float wavg=0,tavg=0;

void swap(int *x,int *y)
{
 int tmp;
 tmp = *x;
 *x = *y;
 *y = tmp;
}

void main()
{
 int i, j;
 printf("Enter no: of processes :");
 scanf("%d",&n);

 printf("Enter priority of each process:");
 for(i=0;i<n;i++)
 {
 p[i] = i+1;
  scanf("%d",&pr[i]);
 }
 printf("\nEnter Arrival time of each process:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&at[i]);
 }
 printf("Enter Burst time of each process:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&bt[i]);
 }
printf("\nProcess\t\tC Time\t\tTA Time\t\tWait Time");
 int min,pos,tmp;
 for(i=0;i<n;i++)
 {
   min = at[i],pos=i;
   for(j=i;j<n;j++)
   {
     if(at[j]<min)
     {
       min = at[j];
       pos = j;
     }
   }

   if(pos!=i)
   {
     swap(&at[pos],&at[i]);
     swap(&bt[pos],&bt[i]);
     swap(&p[pos],&p[i]);
     swap(&pr[pos],&pr[i]);
   }
 }
 int max=0,ct=at[0];
 j=0,pos=0;
 for(i=0;i<n;i++)
 {
   if(i!=0)
   {
     max = pr[i];
     for(j=1;j<ct;j++)
     {
       if(max<=pr[j])
       {
        max = pr[j];
        pos = j;
       }
    }
         pr[pos] = 0;
     swap(&at[i],&at[pos]);
    }
      pr[pos]=0;
      ct = ct+bt[pos];
      tat = ct - at[pos];
      wt = tat - bt[pos];
	wsum+=wt;
	tsum+=tat;
         printf("\nP[%d]\t\t%d\t\t%d\t\t%d",p[pos],ct,tat,wt);
}
wavg=wsum/n;
tavg=tsum/n;
printf("\nAverage Turn Aroung Time: %f",tavg);
printf("\nAverage Waiting Time: %f ",wavg);

printf("\n");
}
                                  
