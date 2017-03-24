#include<stdio.h>
main()
{	int n,x,i,top=0,a[5];
	printf("\nStack size= 30\nStack is Empty\n");
	xx:printf("\n1.PUSH\n2.POP\n3.Display Stack\n4.Exit\nEnter Option:");
	scanf("%d",&n);
	switch(n)
	{	case 1: printf("\nEnter the data:");
			scanf("%d",&x);
			if(top==4)
			{	printf("\nStack is FULL\n");
				break;
			}
			else
			{
				a[top]=x;
				top++;
				goto xx;
			}
		case 2: if(top==0)
			{	printf("\nStack is Empty\n");
				break;
			}
			else
			{	printf("\nLast Entry: %d",a[top-1]);
				top--;
				goto xx;
			}
		case 3:if(top==0)
			{	printf("\nNothing to Display");
				goto xx;
			}
			else
			for(i=0;i<top;i++)
			{	printf("%d->",a[top-i-1]);
				
			}
			printf("\n");
			goto xx;
		case 4: printf("\nTerminating\n");
			break;
		default:printf("\nInvalid Option\n");
			break;
	}
			
}	
