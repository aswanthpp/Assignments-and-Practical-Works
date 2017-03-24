#include<iostream>
using namespace std;
int c=0;
class Nos1
{	
	public:
		Nos1()
		{	c++;
			cout<<"\nClass-1 Constructor Invoked";
			cout<<"\nActive Object Number :"<<c;
			cout<<"\n";
		}
		~Nos1()
		{	c--;
			cout<<"\nClass-1 Destruct Invoked";
			cout<<"\nActive Object Number :"<<c;
			cout<<"\n";
		}
};
class Nos2
{	public:
		Nos2()
		{	c++;
			cout<<"\nClass-2 constructor Invoked ";
			cout<<"\nActive Object Number : "<<c;
			cout<<"\n";
		}
		~Nos2()
		{	c--;
			cout<<"\nClass-2 Destructor Invoked ";
			cout<<"\nActive Object Number : "<<c;
			cout<<"\n";
		}
};
class Nos3
{       public:
                Nos3()
                {       c++;
                        cout<<"\nClass-3 constructor Invoked ";
                        cout<<"\nActive Object Number : "<<c;
			cout<<"\n";
                }
                ~Nos3()
                {       c--;
                        cout<<"\nClass-3 Destructor Invoked ";
                        cout<<"\nActive Object Number : "<<c;
			cout<<"\n";
                }
};			
main()
{	Nos1 p1;
	Nos2 p2;
	Nos3 p3;
	
	if(cout<<"\nControl inside if statement")
	{	Nos2 p4;
		Nos3 p5;
		cout<<"\ngoing outside if statement ";
	}
	Nos1 p6;
	cout<<"\nstatements are ver, control leaving main";
	return 0;
} 
		
	
