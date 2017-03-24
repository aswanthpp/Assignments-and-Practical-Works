#include<iostream>
using namespace std;
class stack        
{	public:
	int top,s[10],max;
	stack()
	{	top=-1;
	}
	void push(int n)
	{	if(top>=max-1)
		{	cout<<"\nOverflow";
		}
		else
		{	s[++top]=n;
		}
	}
	void pop()
	{	       
		if(top<0)
                {       cout<<"\nUnderflow";
                }
		else
		{
                cout<<"\nPopped data:"<<s[top--];
		}
        }
	void display()
	{	cout<<"\nStack Contents:";
		for(int i=0;i<=top;i++)

			cout<<s[i]<<" ";
		cout<<"\n";
	}
};

main()
{       int n;
       stack p;
	cout<<"\nEnter stack size:";
	cin>>p.max;
       xx: cout<<"\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter Option:"; 
        cin>>n;
        switch(n)
        {        case 1:cout<<"\nEnter data:";  
                        cin>>n;
                        p.push(n); goto xx;
		case 2:p.pop(); goto xx;
		case 3:	p.display();goto xx;
		case 4:return 0;
		default:cout<<"\nInvalid Option";
			goto xx;
	}
}

