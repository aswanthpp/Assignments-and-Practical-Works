#include<stdio.h>
#include<stdlib.h>
struct node 
{	int data;
	struct node *next;
	struct node *prev;
};
struct node *header=NULL;
struct node *p;
void insert(struct node *,int ,int);
void delete(struct node *,int);
void display(struct node *);
main()
{	int n,x,pos;
	for(;;)
	{	printf("\nInsertion\n2.Display\n3.Deletion\n4.exit\nEnter option:");
		scanf("%d",&n);
		if(n==1)
		{	printf("\nEnter data:");
			scanf("%d",&x);
			printf("\nEntre option:");
			scanf("%d",&pos);
			insert(header,x,pos);
		}
		else if(n==2)
			display(header);
		else if(n==3)
		{	printf("\nEnetr position:");
			scanf("%d",&pos);
			delete(header,pos);
		}
		else
			break;
	}
}
void insert(struct node *p,int x,int pos)
{	struct node *p1;
	int c=1;
	if(p==NULL)
	{	p=(struct  node *)malloc(sizeof(struct node));
		p1->data=x;
		p->next=NULL;
		p->prev=NULL;
		header=p;
	}
	else
	{	p1=(struct node *)malloc(sizeof(struct node));
		p1->data=x;
		p->next=NULL;
		p->prev=p;
		header=p;
		if(pos==1)
		{	p1->next=header;
			header=p1;
		}
		else
		{	for(;;)
			{	if(p->next==NULL||c==(pos-1))
					break;
				p=p->next;
				c++;
			}
			p1->next=p->next;
			p->next=p1;
			p1->prev=p;
			p->prev=p->prev;
		}
	}
}
void delete(struct node *p,int pos)
{	struct node *temp1;
	int c=1;
	if(p==NULL)
		return;
	else
	{	if(pos==1)
		{	header=p->next;
			free(p);
			p->prev=NULL;
		}
		else
		{	while(pos!=c)
			{	temp1=p;
				p=p->next;
				c++;
			}
			temp1->next=p->next;
			temp1->prev=p->prev;
		}
	}
}
void display(struct node *p)
{	while(p!=NULL)
	{	printf("\n%d-->%u-->%u",p->data,p->next,p->prev);
		p=p->next;
	}
}
	
	
