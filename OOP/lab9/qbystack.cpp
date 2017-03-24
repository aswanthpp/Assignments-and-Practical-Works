#include<iostream>
#include<stdlib.h>
using namespace std;
template<class Type>

class Stack
{
 	Type s[10],at[10];
	int top,n;
public:
	Stack()
	{
		top=-1;
		cout<<"\n\tEnter the Stack Size : ";
		cin>>n;
	}
	void push(Type a)
	{
		if(top<n-1)
		{	++top;
			copy(a);	
		}
		else
			cout<<"\n\tstack is full"<<endl;
	}
	void pop()
	{	if(top<0)
		cout<<"\n\tstack is empty.\n";
		else
		{
		cout<<"\n\tPoped data : "<<s[top--];
		}
	}	
	void copy(Type a)
	{	for(int i=top;i>0;i--)
		{	at[top-i]=s[i-1];
		}
		s[0]=a;
		for(int i=1;i<=top;i++)
		{	s[i]=at[top-i];
		}
	}	
	void operation();
	void display()
	{	for(int i=0;i<n;i++)
			cout<<" "<<s[i];
	}
};
template<class Type>void Stack<Type> :: operation()
{	int x,i;
	Type a;
	cout<<"\n1.PUSH\n2.POP\n3.Exit\nEnter Option : ";
	cin>>x;
	switch(x)
	{	case 1 :cout<<"\nEnter the data: ";
			cin>>a;
			push(a);
			break;
		case 2 :pop();
			break;
	}
} 
main()
{	int ch;
	cout<<"*********************Queue Using Stack *******************\n";
	cout<<"\nINT Stack :";
	Stack<int> stk1;
	cout<<"\nFLOAT Stack :";
	Stack<float> stk2;
	while(1)	
	{	cout<<"\n\n1.INT STACK\n2.FLOAT STACK\n3.Display Contents\n4.Exit\n\tEnter Option : ";
		cin>>ch;
	switch(ch)
	{
		case 1 :stk1.operation();
			break;
		case 2 :stk2.operation();
			break;
		case 3: cout<<"\nInt Stack Contents : ";stk1.display();
			cout<<"\nFloat Stack Contents :";stk2.display();
			cout<<"\n";			
			break;
		default : exit(0);
	}	
	}
} 
