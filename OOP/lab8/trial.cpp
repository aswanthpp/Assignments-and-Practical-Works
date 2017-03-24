#include<iostream>
using namespace std;
class Base
{	public:
		 virtual void display1()
                {       cout<<"\nInside Base Class";
                }
		void display()
		{	cout<<"\nInside Base Class";
		}
};
class Derived:public Base
{	public:
		 void display1()
                {       cout<<"\nInside Derived Class";
                }
		void display()
		{	cout<<"\nInside Derived Class";
		}
};
main()
{	int f;
	Base *a;
        Derived b;
        a=&b;

	cout<<"\n1.Using Virtual\n2.Without Virtual Function";
	xx:cout<<"\nEnter Option:";
	cin>>f;
	switch(f)
	{	 case 1:a->display1();
			goto xx;
		case 2:a->display();
			goto xx;
		default: return 0;
	}
	cout<<"\n";
}
	
	

