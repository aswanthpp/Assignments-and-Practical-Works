#include <stdio.h>
#include <stdlib.h>
#define size 10

void enq(int);
void deq();
void check(int);
void display();

int a[size];
int front=-1, rear=-1;
 
void main()

{

    int n, ch;
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
  
    while (1)
    {
	printf("\nEnter Option No. : ");    
	scanf("%d", &ch);
        switch (ch)
        {

        case 1: printf("\nEnter Data: ");
                scanf("%d",&n);
                enq(n);
                break;

        case 2: deq();
                break;

        case 3: display();
		break;

        case 4: printf("\nTerminated Externally");
            	exit(0);

        default: printf("\nInvalid Option Entry");

        }

    }

}
void enq(int data)
{	if (rear>=size-1)
    	{	printf("\nQueue is FULL");
        	return;
    	}

    if ((front == -1) && (rear == -1))
    {	front++;
        rear++;
        a[rear] = data;
        return;
    }    
    else
	check(data);

    rear++;

}

void check(int data)

{

    int i,j;
    for (i = 0; i <= rear; i++)
    {	if (data >= a[i])
        {	 for (j = rear + 1; j > i; j--)
			a[j] = a[j - 1];
            a[i] = data;
            return;

        }

    }
    a[i] = data;

}
void deq()

{

    int i;
    if ((front==-1) && (rear==-1))
    {	 printf("\nQueue is Empty");
	return;
    }
	else	if(front>rear)
	{	printf("\nQueue is Empty");
		return;
	}
	else
	{	printf("\nDequeued Element:%d",a[0]);
		for(i=0;i<rear;i++)
		a[i]=a[i+1];
		rear--;
		
	}

}
       
void display()

{	 if ((front == -1) && (rear == -1))
        {	printf("\nQueue is empty");
		return;
	 }	
	 for (; front<=rear; front++)
      		printf(" %d ", a[front]);

	front=0;

}
