#include<iostream>
using namespace std;
int c=0;
class Person
{	public:
		Person()
		{	c++;
			cout<<"\nPerson constructor invoked";
			cout<<"\nActive Object Number :"<<c;
			cout<<"\n";
		}
		~Person()
		{	c--;
			cout<<"\nPerson Destructor invoked";
			cout<<"\nActive Object Number : "<<c;
			cout<<"\n";
		}
};
class Faculty:public Person
{	public:
		Faculty()
		{	c++;
			cout<<"\nFaculty Constructor Invoked";
			cout<<"\nActive Object Number:"<<c;
			cout<<"\n";
		}
		~Faculty()
		{	c--;
			cout<<"\nFaculty Destructor Invoked";
			cout<<"\nActive Object Number : "<<c;
			cout<<"\n";

		}
		
};
class Student:public Person
{	public:
		Student()
		{	c++;
			cout<<"\nStudent Constructor Invoked";
			cout<<"\nActive Object Number:"<<c;
			cout<<"\n";
		}
		~Student()
		{	c--;
			cout<<"\nStudent Destuctor Invoked";
			cout<<"\nActive Object Number : "<<c;
			cout<<"\n";
		}
};
main()
{	int x;
		cout<<"\n1.Declare Person Object\n2.Declare Faculty Object\n3.Declare Student Object\n4.Destruct Person Object\n5.Destruct Faculty Object\n6.Destrut Student Object";
	  xx:cout<<"\nEnter Option:";
		cin>>x;
		switch(x)
		{	case 1:{ Person *p1= new Person();}goto xx;
			case 2:{ Faculty *p2=new Faculty();}goto xx;
			case 3: {Student *p3=new Student();}goto xx;
			case 4:p1.~Person();goto xx;
			case 5:p2.~Faculty();goto xx;
			case 6:p3.~Student();goto xx;
			default: return 0;
		}
}
		
