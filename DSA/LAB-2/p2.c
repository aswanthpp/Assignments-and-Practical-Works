
//Aswanth P P 15CO112
//Implement Merge sort using array

#include<stdio.h>
void merge(int arr[],int l,int m,int r)
{	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[30],R[30];
	for(i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(j=0;j<n2;j++)
		R[j]=arr[m+1+j];
	i=0;
	j=0;
	k=l;
	while(i<n1&&j<n2)
	{	if(L[i]<=R[j])
		{	arr[k]=L[i];
			i++;
		}
		else
		{	arr[k]=R[j];		
			j++;
		}
		k++;
	}
	while(i<n1)
	{	arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{	arr[k]=R[j];
		j++;
		k++;
	}
}
void mergesort(int arr[],int l,int r)
{	int m;
	if(l<r)
	{	 m=(l+r)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
main()
{	int a[10],n,i;
	printf("\nEnter array size:");
	scanf("%d",&n);
	printf("\nEnter array Members:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	printf("\nSorted array:");
	for(i=0;i<n;i++)
	{	printf("%d ",a[i]);
	}
	printf("\n");
}		
