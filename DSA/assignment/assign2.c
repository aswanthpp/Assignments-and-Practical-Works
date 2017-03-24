#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	double time1;
	clock_t t,e;
   	 int *p,temp;
    	 long long int  i,j,c,root,k=50000; 
   p=(int *) malloc(1000000*sizeof(int));
   
while(k<=500000)
{	for(i=0;i<k;i++)
		*(p+i)=rand()%1000;	
	t=clock();
    for(i=1;i<k;i++)
    {
        c=i;
        do
        {
           root = (c-1)/2;             
            if (*(p+root)<*(p+c))   
            {
                temp=*(p+root);
		*(p+root)=*(p+c);
		*(p+c)=temp;
            }
            c=root;
        }while(c!=0);
    }
    for (j=k-1;j>=0;j--)
    {
        temp=*p;
	*p=*(p+j);
	*(p+j)=temp;
        root=0;
        do 
        {
           c=2*root+1;    
            if((*(p+c)<*(p+c+1))&&c<j-1)
                c++;
            if (*(p+root)<*(p+c)&&c<j)    
            {
                temp=*(p+root);
		*(p+root)=*(p+c);
		*(p+c)=temp;
            }
            root=c;
        }while(c<j);
    } 
	e=clock();
	time1=((double)(e-t))/(CLOCKS_PER_SEC);
	printf("%lld\t:%lfs\n",k,time1);
	k+=25000;
}
   
}
