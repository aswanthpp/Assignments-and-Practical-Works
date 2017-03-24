#include<iostream>
using namespace std;
int s[20];
class stack
{	public:
	int t1,t2,max,x,f;
	stack()
	{	t1=-1;
		t2=max;
	}
	void push()
	{	if(t1==t2)
		{	cout<<"\nOverflow";
		}
		else
		{	cout<<"\nFrom 1.R end 2.L end\nEnter option:";
			cin>>f;
			cout<<"\nEnter data:";
			cin>>x;
			if(f==2)
			{	s[++t1]=x;
			}
			else
			{	s[--t2]=x;
			}
		}
	}
	void pop()
	{	cout<<"\nFrom 1.R end\n2.L end\nEnter option:";
                        cin>>f;
		if(f==2)
		{	if(t1<0)
			{	cout<<"\nUnderflow";
			}
			else
			{	cout<<"\nPopped data:"<<s[t1--];
			}
		}
		else
		{ 	if(t2>=max)
                        {       cout<<"\nUnderflow";
                        }
                        else
                        {       cout<<"\nPopped data:"<<s[t2--];
                        }
                }
	}
	void display()
	{	cout<<"\nStack contents:";
		for(int i=0;i<max;i++)
		cout<<s[i]<<" ";
		cout<<"\n";
	}
};
main()
{	int n;
	stack a;
	cout<<"\nEnter size:";
	cin>>a.max;
	cout<<"\n1.Push\n2.Pop\n3.Display\n4.Exit";
	xx: cout<<"\nEnter Option:";
		cin>>n;
		switch(n)
		{	case 1:a.push();goto xx;
			case 2:a.pop();goto xx;
			case 3:a.display();goto xx;
			case 4:return 4;
			default:cout<<"\nInvalid Option";
				goto xx;
		}
}

