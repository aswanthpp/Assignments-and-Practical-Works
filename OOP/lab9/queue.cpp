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
	}
	void enq(Type a)
	{	if(r>=n-1)
		{	cout<<"\n\tQueue is full ";
		}
		else
		{	Q[++r]=a;
		}
	}
	void deq()
	{	if(f==r)
		{	cout<<"\n\tQueue is Empty ";
		}
		else
		{	int data=Q[++f];
				Q[f]=0;
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
		
	
