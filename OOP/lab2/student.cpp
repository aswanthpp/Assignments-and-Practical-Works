#include<iostreeam>
using namespace std;
class student
{	private:
	char name[20];
	int cgpa;
	public:
	void read();
	void sortname();
	void sortcg();
	void display();
}s[50];
void student::read()
{	cout<<"\nEnter name:";
	cin>>name;
	cout<<"\nenter CGPA :";
	cin>>cgpa;
}
void student::display()
{	cout<<name<<"\t"<<cgpa<<"\n";
}
main()
{	int n,x,min,k;
	student t;
	cout<<"\nEnter number of students:";
	cin>>n;
	for(int i=0;i<n;i++)
	{	cout<<"\nEnter student "<<i+1<<" Details :";
		s[i].read();
	}
	cout<<"\n1.Sort name\t2.Sort cgpa\t3.Exit";
	cout<<"\nEnetr option :";
	cin>>x;
	switch(x)
	{	case 1:	for(i=0; i<n; i++)
			{
			for(j=1; j<5; j++)
			{
				if(strcmp(str[j-1], str[j])>0)
				{
					strcpy(t, str[j-1]);
					strcpy(str[j-1], str[j]);
					strcpy(str[j], t);
				}	
			}
			}
		case 2: for(i=0;i<n;i++)
			{	min=s[i].cgpa;
				k=i;
				for(j=i;j<n;j++)
				{	if(min<s[j].cgpa)
					{	min=s[j].cgpa;
						k=j;
					}
				}		           
				t=s[i];
				s[i]=s[k];
				s[k]=t;
			} goto xx;	
		case 3: return 0;
		default : cout<<"\nInvalid Option \n";
				goto xx;
	}
