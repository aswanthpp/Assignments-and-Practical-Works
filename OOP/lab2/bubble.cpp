#include<iostream>
using namespace std;
int n;
class sort
{
	public:
	int a[50];
	void insert(int n);
	void bubble(int n);
	void selection(int n);
	void insertion(int n);
	void merge(int n);
	void merge1(int l,int u);
	void mergesort(int l,int m,int u); 
	void quick(int ,int);
	void display(int n);
	void swap(int * x,int *y);
	int partition(int ,int );
};
void sort::swap(int *x,int *y)
{	int t;
	t=*x;
	*x=*y;
	*y=t;
}
void sort::insert(int n)
{	cout<<"\nEnter Data List:";
	for(int i=0;i<n;i++)
	{	cin>>a[i];
	}	
}
void sort::bubble(int n)
{	for(int i=0;i<n;i++)
	{	for(int j=0;j<n-i-1;j++)
		{	if(a[j]>a[j+1])
			{	swap(&a[j],&a[j+1]);
			}
		}
	}
cout<<"\nBubble ";
display(n);
}
void sort::selection(int n)
{	int min,j,k;
	for(int i=0;i<n;i++)
	{	min=a[i];
		k=i;
		for(j=i;j<n;j++)
		{	if(a[j]<min)
			{	min=a[j];
				k=j;
			}
		}
		swap(&a[i],&a[k]);
	}
cout<<"\nSelection ";
display(n);
}
void sort::insertion(int n)
{	int i,j;
	for(i=1;i<n;i++)
 	{	j = i;
  		while(j!=0 && (a[j] < a[j-1]))
  		{
    			swap(&a[j],&a[j-1]);
    			j--;
  		}			
 	}	
	cout<<"\nInsertion ";
	display(n);
}
void sort::merge(int n)
{	int l=0;
	int u=n-1;
	merge1(l,u);
	cout<<"\n Merge ";
	display(n);
}
void sort::merge1(int l,int u)
{	int m;
	if(l<u)
	{
		m=l+(u-l)/2;
		merge1(l,m);
		merge1(m+1,u);
		mergesort(l,m,u);
	}
}
void sort::mergesort(int l,int m,int u)
{	int L[25],R[25],n1,n2,k,i=0,j=0;
	n1=m-l+1;
	n2=u-m;
	for(i=0;i<n1;i++)
		L[i]=a[l+i];
	for(j=0;j<n2;j++)
		R[j]=a[m+1+j];
	i=0;j=0;k=l;
	while(i<n1&&j<n2)
	{	if(L[i]<R[j])
		{	a[k]=L[i];
			i++;
			k++;
		}
		else
		{	a[k]=R[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{	a[k]=L[i];
		i++;
		k++;
	}
	while(i<n2)
	{	a[k]=R[j];
		k++;
		j++;
	}
}
void sort::quick(int l,int u)
{	if(l<u)
    {
        int pi=partition(l,u);
        quick(l,pi-1);
        quick(pi+1,u);
    }
}
int sort::partition (int l,int u)
{   int p=a[u];
    int i=(l-1),j;
    for(j=l;j <=u-1;j++)
    {	if(a[j]<= p)
        {	i++;
 		swap(&a[i],&a[j]);
        }
    }
    swap(&a[i + 1], &a[u]);
    return (i + 1);
}
void sort::display(int n)
{	cout<<" sort Results:";
	for(int i;i<n;i++)
		cout<<a[i]<<" ";
}
main()
{	int x;
	sort s;
	cout<<"\n1.Bubble 2.Selection 3.Insertion 4.Merge 5.Quick 6.Exit";
	xx:cout<<"\nEnter Option:";
	cin>>x;
	switch(x)
	{	case 1:	cout<<"\nEnter Number of elements:";cin>>n;s.insert(n);	s.bubble(n);goto xx;
		case 2:	cout<<"\nEnter Number of elements:";cin>>n;s.insert(n);	s.selection(n);goto xx;
		case 3:	cout<<"\nEnter Number of elements:";cin>>n;s.insert(n);	s.insertion(n);goto xx;
		case 4:	cout<<"\nEnter Number of elements:";cin>>n;s.insert(n);	s.merge(n);goto xx;
		case 5:	cout<<"\nEnter Number of elements:";cin>>n; s.insert(n);	s.quick(0,n-1); cout<<"\nQuick ";s.display(n); goto xx;
		case 6:return 0;
		default: cout<<"\nInvalid Option\n";
			goto xx;
	}
}
	
