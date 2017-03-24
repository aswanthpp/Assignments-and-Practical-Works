#include<stdio.h>
#include<stdlib.h>
struct node
{	int data;	
	struct node *next;
};
struct node *newnode,*temp,*ptr;
struct node *first=NULL,*last=NULL;
struct node * create_node(int val)
{	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{	printf("\nMemory Was not allocated");
		return 0;
	}
	else
	{	newnode->data=val;
		newnode->next=NULL;
		return newnode;
	}
}
void push(int x);
void display()
{	if(first==NULL)
	{	printf("\nNothing to Display\n");
	}
	else
	{	for(ptr=first;ptr!=NULL;ptr=ptr->next)
		printf("%d->",ptr->data);
	}
}
void pop();
main()
{	int n,x;
	xx:	printf("\n1.PUSH\n2.POP\n3.Display Stack\n4.Exit\nEnter choice:");
		scanf("%d",&n);
	switch(n)
	{	 case 1: printf("\nEnter data:");
			scanf("%d",&x);
			push(x);
			goto xx;
		case 2: pop();
			goto xx;
		case 3:	printf("\n\n");
			display();
			goto xx;
		case 4:printf("\nTerminated\n");
			break;
		default:printf("\nInvalid OptionEntry\n");
	}
}
void push(int x)
{	newnode=create_node(x);
	if(first==last&&first==NULL)
	{	first=last=newnode;
		first->next=NULL;
		last->next=NULL;
	}
	else
	{	temp=first;
		first=newnode;
		first->next=temp;
	}
	printf("\nInserted");
}
void pop()
{	if(first==NULL)
	{	printf("\nStack is Empty\n");
	}
	else
	{	printf("\nLast Entry : %d",first->data);
		first=first->next;
		printf("\nElement Deleted\n");
	}
}
