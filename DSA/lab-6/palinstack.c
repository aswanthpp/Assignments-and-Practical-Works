#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[20];
int top=0;
void push(char x);
char pop();
main()
{	char a[10],c;
	int l,i,f=0;
	printf("\nEnter string:");
	scanf("%s",a);
	l=strlen(a);
	printf("\n%d\n",l);
	if(l%2==0)
	{	for(i=0;i<l/2;i++)
		{	push(a[i]);
		
		}
		for(;i<
cument
		{	c=pop();
			printf("\n##%c##",c);
		if(a[i]!=c)
			{	printf("\nString is not palindroome");
				f=1;
				exit(0);
			}
		}
	}
	else
	{	for(i=0;i<l/2;i++)
		{	push(a[i]);
			printf("&&%c&&",a[i]);
		}
		i++;
		for(;i<l;i++)
		{	 c=pop();
                        printf("\n##%c##",c);
                if(a[i]!=c)
			{	printf("\nString is not palindrome");
				f=1;
				exit(0);
			}
		}
	}
	if(f==0)
		printf("\nString is palindrome");
}
void push(char x)
{	
	if(top==19)
	{	printf("\nStack is full");
		exit(0);
	}	
	else
	{	s[top]=x;
		top++;
	}
}
char pop()
{	if(top==-1)
	{	printf("\nStack is empty");
		exit(0);
	}
	else
	{	top--;
		return s[top];
	}
}
	
