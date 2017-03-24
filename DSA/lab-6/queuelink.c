#include<stdio.h>
#include<stdlib.h>
struct node 
{	int data;
	struct node *next;
};
struct node *head=NULL;
void enqueue(struct node *p,int data);
void dequeue(struct node *p);
main()
{	int x,n;
	xx:printf("\n1.Enqueue\n2.Dequeue\n3.Exit\nEnter option:");
	scanf("%d",&n);
	switch(n)
	{	case 1: printf("\nEnter data:");
			scanf("%d",&x);
			enqueue(head,x);
			goto xx;
		case 2:dequeue(head);
			goto xx;
		case 3:printf("\nTerminated");
			exit(0);
		default:printf("\nInvalid Entry");
			goto xx;
	}
}
void enqueue(struct node *p,int data)
{	if(p==NULL)
	{	p=(struct node *)malloc(sizeof(struct node));
		p->data=data;
		p->next=NULL;
		head=p;
	}
	else
	{	struct node *p1=(struct node *)malloc(sizeof(struct node));
		p1->data=data;
		p1->next=NULL;
		for(;;)
		{	if(p->next==NULL)
			break;
			p=p->next;
		}
		p->next=p1;
	}
}
void dequeue(struct node *p)
{	if(p==NULL)
	{	printf("\nQueue is empty");
	}
	else
	{	head=p->next;
		printf("\nDequeueed element:%d",p->data);
		free(p);
	}

}
