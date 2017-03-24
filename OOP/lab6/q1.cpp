#include<iostream>
using namespace std;
class Publication
{	private:
		char title[50];
		float price;
	public:
		void getdata()
		{	cout<<"\nEnter Title:";
			cin.ignore();
			cin.getline(title,50);
			cout<<"Enter price:";
			cin>>price;
		}
		void putdata()
		{	cout<<"\n"<<title<<"\t\t "<<price;
		}
};
class Book:public Publication
{	private:	
		int pcount;
	public:
		void getdata()
		{	
			Publication::getdata();
			cout<<"Enter Page Count : ";
			cin>>pcount;
		}
		void putdata()
		{	
			Publication::putdata();
			cout<<"\t"<<pcount;
		}
	
};
class Tape:public Publication
{	private:
		float ptime;
	public:
		void getdata()
		{
			Publication::getdata();
			cout<<"Enter Play Time : ";
			cin>>ptime;
		}
		void putdata()
		{	
			Publication::putdata();
			cout<<"\t"<<ptime;
		}
};
main()
{	Book b[20];
	Tape t[20];
	char ch='A';
	int c1,c2,n;
	cout<<"\nEnter Number of Publications: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{	cout<<"\n Publication "<<ch<<" Details : \n";
		cout<<"\nEnter  number of Books: ";
		cin>>c1;
		for(int i=0;i<c1;i++)
		{	cout<<"\nBook "<<i+1<<" Details :\n";
			b[i].getdata();
		}
		cout<<"\nEnter number of Tapes : ";
		cin>>c2;
		for(int i=0;i<c2;i++)
		{	cout<<"\nTape "<<i+1<<" Details :\n";
			t[i].getdata();
		}
		ch++;
	}
	ch='A';
	for(int i=0;i<n;i++)
	{
		cout<<"\n \tPUBLICATION "<<ch<<" Details\n____________________________\n";
		cout<<"\n   Book Deatails\n";
        	cout<<"*******************";
		cout<<"\nTITLE\t\tPRICE\tPAGE Nos.\n";
		for(int i=0;i<c1;i++)
		{	b[i].putdata();
		}
		cout<<"\n\n   Tape Deatails\n";
        	cout<<"*******************";
		cout<<"\nTITLE\t\tPRICE\tPLAY TIME\n";
		for(int i=0;i<c2;i++)
		{	t[i].putdata();
		}
		ch++;
	}
	cout<<"\n\n";
/*
	xx: cout<<"\nBook(1) or Tape(0) : ";
	cin>>f;
	if(f==1)
	{	b.getdata();
		cout<<"\n   Book Deatails\n";
		cout<<"*******************";
		b.putdata();
	}
	else if(f==0)
	{	t.getdata();
		cout<<"\n   Tape Details\n";
		cout<<"****************";
		t.putdata();
	}
	else
	{	cout<<"\nInvalid option";
	}
	cout<<"\n\nWant to continue Yes(1) or No (0) : ";
	cin>>f; 
	if(f==1)
		goto xx;
*/
}

