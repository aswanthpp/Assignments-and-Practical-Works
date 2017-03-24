#include<iostream>
using namespace std;
class queue
{	public:
	int f,q[10],max;
	queue()
	{	f=-1;
		
	}
	void enq(int n)
	{	if(f>=max-1)
		{	cout<<"\nOverflow";

		}
		else
		{	q[++f]=n;
		}
	}
	void deq()
	{if(q[0]==-1)
	{	cout<<"\nUnderflow";
	}
	else
	{	cout<<"Dequed Data:"<<q[0];
		for(int i=0;i<f;i++)
			q[i]=q[i+1];
		q[f]=-1;
		f--;
	}
	}
	void display()
	{	cout<<"Queue Contents:";
		for(int i=0;i<=f;i++)
			cout<<q[i]<<" ";
	}
};
int main()
{	int n,x,i;
	queue s;
	cout<<"\nEnter queue size:";
	cin>>s.max;
	for(i=0;i<s.max;i++)
	s.q[i]=-1;
		cout<<"\n1.Enq\n2.Deq\n3.Display\n4.Exit";
	xx:	cout<<"\nEnter Option:";
	cin>>n;
	switch(n)
	{	 case 1:cout<<"\nEnte Data:";
			cin>>x;
			s.enq(x);
			goto xx;
		case 2:s.deq();
			goto xx;
		case 4: return 0;
		case 3: s.display();
			goto xx;
		default : cout<<"\nInvalid Option";
				goto xx;
	}
	return 0;
}
		
