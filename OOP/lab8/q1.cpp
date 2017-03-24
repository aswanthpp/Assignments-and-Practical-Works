#include<iostream>
using namespace std;
class User
{	public:
		string name;
		int age;
		User(string n,int r)
		{
			name=n;
			age=r;
		}
		virtual void display()
                {       cout<<"\nName :"<<name;
                        cout<<"\nAge : "<<age;
		}
};
class Student:public User
{	public:
		string course;
		int rno,mark;
		Student(string c,int r,int m,string a,int n)
		:User(a,n)
		{	
			course=c;
			rno=r;
			mark=m;
		}
		void display()
		{	User::display();
			cout<<"\nRoll No. : "<<rno;
			cout<<"\nCourse : ";
			for(int i=0;i<5;i++)
			{	cout<<"\n\tCourse-"<<i+1<<" : "<<course[i];
			}
			cout<<"\nTotal Mark : "<<mark;
		}
			
};
class Teacher:public User
{	public:
		string sub,hr;
		Teacher(string s,string h,string c,int n)
		:User(c,n)
		{
			sub=s;
			hr=h;
		}
		void display()
		{ 	User::display();
			cout<<"\n\tSubject\t Hour :";			
			for(int i=0;i<3;i++)
			{
			cout<<"\n\t"<<i+1<<". "<<sub<<"\t"<<hr;
			}
		}
};		
main()
{	int f;
	string a,c,hr;
	int x,rno,m;
	User *u;
	cout<<"\n1.Student\n2.Teacher";
	xx: cout<<"\n\nEnter Option:";
	cin>>f;
	switch(f)
	{	case 1:	
			cout<<"Enter Name and Age :";
			cin>>c>>x;
			cout<<"\nEnter Roll Number :";
			cin>>rno;
			for(int i=0;i<5;i++)
			{	cout<<"\nEnter Course Code-"<<i+1<<" : ";
				cin>>a[i];
			}
			cout<<"\nEnter Total Marks:";
			cin>>m;
			{Student S(a,rno,m,c,x);
				u=&S;
			cout<<"\nStudent Deatils :";
			S.display();}
			goto xx;
		case 2:
			cout<<"Enter name and age :";
			cin>>c>>x;
			for(int i=0;i<3;i++)
			{	cout<<"\nEnter Sub-"<<i+1<<"and Hour :";
				cin>>a[i]>>hr[i];
			}
			{Teacher T(a,hr,c,x);
			cout<<"\nTecher Details :";
			T.display();}  
			goto xx;
		default: return 0;
	}
	cout<<"\n";		
}
