#include<iostream>
#include<stdlib.h>
using namespace std;
template<class Type>
class Queue
{private:
	Type Q[10];
	int f,r,n;
public:
	Queue()
	{	cout<<"\nEnter Queue Size :";
		cin>>n;
		f=-1;
		r=-1;
		for(int i=0;i<n;i++)
		{	Q[i]=0;
		}
	}
	void enq(Type a)
	{	if((r+1)%n==f)
		{	cout<<"\n\tQueue is full ";
		}
		else
		{	r=(r+1)%n;
			Q[r]=a;
			if(f=-1)
				f=0;
		}
	}
	void deq()
	{	if(f==-1)
		{	cout<<"\n\tQueue is Empty ";
		}
		else
		{	int data;
			data=Q[f];
			Q[f]=0;
			if(f==r)
			{	f=-1;
				r=-1;
			}
			else
				f=(f+1)%n;
			cout<<"\nDequed Data : "<<data;
		}
	}
	void operation()
	{	int ch;
		Type data;
		cout<<"\n1.Enqueue\n2.Dequeue\n3.Display\nEnter Option : ";
		cin>>ch;
		switch(ch)
		{	case 1:cout<<"\nEnter Data : ";
				cin>>data;
				enq(data);
				break;
			case 2:deq();
				break;
			case 3:display();
				break;
		}
	}
	void display()
	{	cout<<"\nQueue Contents : ";
		for(int i=0;i<n;i++)
		cout<<" "<<Q[i];
	}
};
main()
{	int x;
	cout<<"\nINT QUEUE";
	Queue<int>q1;
	cout<<"\nFLOAT QUEUE";
	Queue<float>q2;
	while(1)
	{	cout<<"\n1.INT Queue\n2.FLOAT Queue\n3.Exit\n\tEnter Option : ";
		cin>>x;
		switch(x)
		{	case 1:q1.operation();
				break;
			case 2:q2.operation();
				break;
			default : exit(0);
		}
	}
	cout<<"\n";
}
		
	
