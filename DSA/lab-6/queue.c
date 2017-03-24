#include<stdio.h>
#include<stdlib.h>
void enqueue(int data);
void dequeue();
int q[10],f=0,r=0;
main()
{	int n,x;


	xx:printf("\n1.Enqueue\n2.Dequeue\n3.Exit\nEnter option:");
	scanf("%d",&n);
	switch(n)
	{	case 1:printf("\nEnter data:");
			scanf("%d",&x);
			enqueue(x);
			goto xx;
		case 2:dequeue();
			goto xx;
		case 3:printf("\nTerminated");
			exit(0);
		default:printf("\nInvalid Option");
			goto xx;
	}
}
void enqueue(int x)
{	if(r==10)
	{	printf("\n****Q is full****\n");
	}
	else
	{
		q[r]=x;
		r++;
	}
}
void dequeue()
{	if(f==r)
	{	printf("\n****Q is empty****\n");
	}
	else
	{	printf("\nDequeueed data:%d",q[f]);
		f++;
	}
}
	
