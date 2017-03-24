#include<stdio.h>
#include<stdlib.h>
struct node
{	int data;
	struct node *next;
}s[10];
void insert(struct node h,int data);
void display(int n);

main()
{	int i,j;
	printf("\nEnter Number of Vertives:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	for(j=0j<n;j++)
	{	printf("\nVertex %d->%d is present 1 or 0 :");
		scanf("%d",&a[i][j]);
		insert(s[i],a[i][j]);
	}
	display(head,n);
}
void insert(struct node *p,int data)
{	if(h==NULL)
	{	p=(struct node *)malloc(sizeof(struct node));
		p->data=data;
		p->next=NULL;
		head=p;
		
	}
	else
	{	struct node *p1=(struct node *)malloc(sizeof(struct node));
		p1->data=data;
		p1->next=NULL;
		while(p->nextnext!=NULL)
			p=p->next;
		p->next=p1;
	}
}
void display(int n)
{	int i,j;
	printf("\nAdjacency Matrix:\n");
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	printf("\nAdjacency List:\n");
	for(i=0;i<n;i++)
	{	printf("%d->",s[i].data);
	}
}

	
		
		
		
	
