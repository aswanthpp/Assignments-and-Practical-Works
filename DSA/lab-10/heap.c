#include<stdio.h>

void main()
{
    int heap[50],temp;
      int  i,j,c,root,k;
	printf("\nEnter no of elements:");
	scanf("%d",&k);
	printf("\nEnter the elements:");
	for(i=0;i<k;i++)
	scanf("%d",&heap[i]);
    for(i=1;i<k;i++)
    {
        c=i;
        do
        {
           root = (c-1)/2;
            if (heap[root]<heap[c])
            {
                temp=heap[root];
                heap[root]=heap[c];
                heap[c]=temp;
            }
            c=root;
        }while(c!=0);
    }
    for (j=k-1;j>=0;j--)
    {
        temp=heap[0];
        heap[0]=heap[j];
        heap[j]=temp;
        root=0;
        do
        {
           c=2*root+1;
            if((heap[c]<heap[c + 1])&&c<j-1)
                c++;
                                 
		if(heap[root]<heap[c]&&c<j)
               {                                                                 		 temp=heap[root];                                                               heap[root]=heap[c];
                heap[c]=temp;
                 }
            root=c;
        }while(c<j);
    }
	printf("\nSorted array:\n");
	for(i=0;i<k;i++)
	printf("%d ",heap[i]);
	printf("\n");
}
	

