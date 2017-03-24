#include<iostream>
using namespace std;
class University
{	public:
		string name,dept,person;
		University(string uname,string dep,string per)
		{	name=uname;
			dept=dep;
			person=per;
		}
		virtual void display()
		{	cout<<"\nUniversity Name : "<<name;
			cout<<"\nDepartment Name : "<<dept;
			cout<<"\nProject Mentor : "<<person;
		}
};
class Company
{	public:
		string name;
		int amnt,num;
		Company(string cname,int a,int n)
		{	name=cname;
			amnt=a;
			num=n;
		}
		virtual void display()
		{	cout<<"\nCompany Name :"<<name;
			cout<<"\nAmount Invested : "<<amnt;
			cout<<"\nNum. of Engineers Assigned : "<<num;
		}
};
class Project:public University,public Company
{	public: 
		string type;
		int time,total;
		Project(string t,int tym,int tot,string cname,int a,int n,string uname,string dep,string per)
		:University(uname,dep,per),Company(cname,a,n)
		{	type=t;
			time=tym;
			total=tot;
		}
		void display()
		{
			University::display();
			Company::display();
			cout<<"\nType of Project : "<<type;
			cout<<"\nTotal Time Duration :"<<time;
			cout<<"\nAmount Granted : "<<total;
		}
};
main()
{	int n;
	string uname,dept,person,cname,type;
	int amnt,total,time,num;
	cout<<"\nEnter Number of Project :";
	cin>>n;
	for(int i=0;i<n;i++)
	{	
		cout<<"\n\nEnter Project-"<<i+1<<" Details :\n";
		cout<<"\nUniversity Name:";cin>>uname;
		cout<<"\nDepartment : ";cin>>dept;
		cout<<"\nPerson assigned :";cin>>person;
		cout<<"\nCompany Name : ";cin>>cname;
		cout<<"\nAmount Invested : ";cin>>total;
		cout<<"\nNum. of People Assigned :";cin>>num;
		cout<<"\nType of Project : ";cin>>type;
		cout<<"\nAmount Granted :";cin>>amnt;
		cout<<"\nTime Duration :";cin>>time;
		cout<<"\n\n\nProject-"<<i+1<<"  Details : \n";
		{
		Project P(type,time,amnt,cname,total,num,uname,dept,person);
		P.display();
		}
	}
			
		/*cout<<"\n\tProject Details ";
		for(int i=0;i<n;i++)
		{	cout<<"\nProject-"<<i+1<<"Details : \n";
			p[i]->display();
		}	*/
}
