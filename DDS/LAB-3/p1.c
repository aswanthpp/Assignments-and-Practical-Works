#include<stdio.h>
#include<stdlib.h>
struct node
{	int i;
	struct node *next;
};
struct node *head,*temp,*mid,*p;
int cnt=0;
void create();
void insert();
void display();
void delete();
void main()
{	int ch=0;
	while(ch!=5)
	{	printf("\n1.Creating List\n2.Insertion at exixsting list\n3.Deletion\n4.Display list\n5.Exit\nEnter the option:");
		scanf("%d",&ch);
		if(ch==1)
		{	create();
			cnt++;
		}
		if(ch==2)
		{	insert();
			cnt++;
		}
		if(ch==3)
		{	delete();
			cnt--;
		}
		if(ch==4)
		{	display();
		}
		if(ch==5)
			break;
	}
}
void create()
{	head=(struct node *)malloc(sizeof(struct node));
	head->next=head;
	printf("\nEnter Data:");
	scanf("%d",&temp->i);
}
void insert()
{	int add,t;
	printf("\nEneter any  number between 1 and %d:",cnt);
	scanf("%d",&add);
	p=head;
	t=1;
	while(t<add)
	{	p=p->next;
		t++;
	}
	printf("%d",p->i);
	mid=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data:");
	scanf("%d",&mid->i);
	mid->next=p->next;
	p->next=mid;
}
void display()
{	p=head;
	printf("%d-->",p->i);
	p=p->next;
	while(p!=head)
	{	printf("%d-->",p->i);
		p=p->next;
	}
}
void delete()
{	int add,t;
	printf("\nEnter any number between 1 and %d:",cnt);
	scanf("%d",&add);
	p=head;
	t=1;
	while(t<add-1)
	{	p=p->next;
		t++;
	}
	printf("%d",p->i);
	mid=p->next;
	p->next=mid->next;
}
	 	

