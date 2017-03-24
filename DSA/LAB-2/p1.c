// Aswanth P P 15CO112
// Insert and delte elements in linked list at any position


#include<stdio.h>
#include<stdlib.h>
struct node
{	int data;
	struct node *adress;
};
struct node *header=NULL;
struct node *current=NULL;
void insert(struct node *,int,int);
void display(struct node *);
void delete(struct node *,int x);
main()
{	int n,i,x,pos;
	
	
	for(;;)
	{	printf("\n1.Insert Element\n2.Display\n3.Delete\n4.Exit\nEnter option:");
		scanf("%d",&n);
		if(n==1)
		{	printf("\nEnter element:");
			scanf("%d",&x);
			printf("\nEnter position:");
			scanf("%d",&pos);
			insert(header,x,pos);
		}
		else if(n==2)
			display(header);
		else if(n==3)
		{	printf("\nEnter position:");	
			scanf("%d",&x);
			delete(header,x);
		}
                 else exit(0);
	}
}
	void insert(struct node *p,int x,int pos)
	{	struct node *p1;
		int c=1;
		if(p==NULL)
		{	p=(struct node *)malloc(sizeof(struct node));
			p->data=x;
			p->adress=NULL;
			header=p;
		}
		else
		{	p1=(struct node *)malloc(sizeof(struct node));
			p1->data=x;
			p1->adress=NULL;
			if(pos==1)
			{	p1->adress=header;
				header=p1;
			}
			else				
			{	for(;;)
			{	if(p->adress==NULL||c==pos-1)
					break;
					p=p->adress;
			}
				p1->adress=p->adress;
				p->adress=p1;
	}	}}
	void display(struct node *p)
	{	while(p!=NULL)
		{	printf("%d ",p->data);
			p=p->adress;
		}
	}
void delete(struct node *p,int x)
{	struct node *temp1;
	int c=1;
	if(p==NULL)
		return ;
	else
	{	if(x==1)
		{	header=p->adress;
			free(p);
		}
		else
		{	while(x!=c)
			{	temp1=p;	
				p=p->adress;
				c++;
			}
			temp1->adress=p->adress;
		}
	}
}
		
							
			
			
