#include<iostream>
using namespace std;
class list
{	private:	
	int data;
	class list *next;
	public:
	void create(class list *p,int);
	void display(class list *p);
	void delete(class list *p);
};
class list *head=NULL;

void list::create(class list *p,int x)
{	if(p==NULL)
	{	p=new class list;
		p->data=data;
		p->next=NULL;
	}
	else
	{	while(p->next!=NULL)
		{	p=p->next;
			
