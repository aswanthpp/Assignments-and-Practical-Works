#include<stdio.h>
#include<stdlib.h>
struct node
{       int data;
        struct node *next;
};
struct node *newnode,*temp,*ptr;
struct node *first=NULL,*last=NULL;

int precedence(char x);

struct node * create_node(int val)
{       newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {       printf("\nMemory Was not allocated");
                return 0;
        }
        else
        {       newnode->data=val;
                newnode->next=NULL;
                return newnode;
        }
}

void push(int x)
{       newnode=create_node(x);
        if(first==last&&first==NULL)
        {       first=last=newnode;
                first->next=NULL;
                last->next=NULL;
        }
        else
        {       temp=first;
                first=newnode;
                first->next=temp;
        }
        printf("\nInserted");
}
void pop()
{       if(first==NULL)
        {       printf("\nStack is Empty\n");
        }
        else
        {       printf("\nLast Entry : %d",first->data);
                                                              70,12-25      90%
		first=first->data;
		printf("\nElement Deleted");
	}
}
main()
{	char a[10];
	int i,l,k;
	printf("\nEnter Infix Expression:");
	scanf("%s",a);
	l=strlen(a);
	for(i=0;i<l;i++)
	{	if(isnum(a[i]))
		{	push(a[i]);
		}
		else if(isalpha(a[i]))
		{	printf("\nAlphabets are enetered");
			exit(0);
		}
		else
		{	k=precedence(a[i]);
			if(k==3)
				push(a[i]);
			else
			{	if(top2==0)
					push(a[i]);
				else
				{	t=pop(c);
		}
	}
}
int precedence(char x)
{	if(x=='(')
		return 3;
	else if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/'||x=='%')
		return 2;
}
