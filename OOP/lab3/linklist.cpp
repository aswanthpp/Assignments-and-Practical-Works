#include<iostream>
using namespace std;
class list
{ private:
	struct node
	{       int data;
        	struct node *next;
	};
	struct node *head;
 

     public:
	list()
	{	head=NULL;
	}
       void insert(int,int );
       void display();
  	void del(int );
	void search(int);
	void rev();
	void swap();

};
void list::insert(int x,int pos)
{       struct node *p=head;
	int c=1;
	if(p==NULL)
        {       p=new struct node;
                p->data=x;
                p->next=NULL;
		head=p;
        }
        else
        {       struct node  *p1=new struct node;
		 p1->data=x;
                p1->next=NULL;
			
		if(pos==1)
		{	p1->next=head;
			head=p1;
		}
		else
		{	
			while(p->next!=NULL&&c!=pos-1)
                       {		p=p->next;
					c++;
			}
		p1->next=p->next;
                p->next=p1;
		}
	}
}

void list::display()
{	 struct node *p=head;
	cout<<"\nList Contents :";

	while(p!=NULL)
	{	cout<<p->data<<" ";
		p=p->next;
	}
}
void list::del(int pos)
{	 struct node *p=head;  
	struct node *temp1;
        int c=1;
        if(p==NULL)
                return ;
        else
        {       if(pos==1)
                {       head=p->next;
                        delete p;
                }
                else
                {       while(pos!=c)
                        {       temp1=p;
                                p=p->next;
                                c++;
                        }
                        temp1->next=p->next;
                }
        }
}
void list::search(int x)
{	 struct node *p=head;
	int c=1;
	while(p!=NULL)
	{	if(p->data==x)
		{	cout<<"\nItem found at Position "<<c;
			return ;
		}
		else
		{	p=p->next;
			c++;
		}
	}
	cout<<"\nItem Not Present";
}
void list::rev()
{	struct node* prev   = NULL;
    	struct node* current = head;
    	struct node* next;
    	while (current != NULL)
    	{
        	next  = current->next; 
        	current->next = prev;  
        	prev = current;
        	current = next;
    	}
    	head = prev;
}
void list::swap()
{	struct node *p=head;
	int tmp;
	while(1)
	{	if(p==NULL)
			return;
		else if(p!=NULL&&p->next==NULL)
			return;
		else if(p!=NULL&&p->next!=NULL)
		{	tmp=p->data;	
			p->data=p->next->data;
			p->next->data=tmp;
			p=p->next->next;
		}
	}

	
}

main()
{	class list s;
	int x,data,pos;
	cout<<"\n1.Insert \n2.Display \n3.Delete \n4.Search \n5.Reverse List\n6.Swap\n7.Exit";
	xx:cout<<"\nOption :";
	cin>>x;
	switch(x)
	{	case 1: cout<<"\nData and Position: ";	cin>>data>>pos;
			s.insert(data,pos);
			goto xx;
		case 2: s.display();
			goto xx;
		case 3:cout<<"\nPosition :";cin>>pos;
			s.del(pos);goto xx;
		case 4:cout<<"\nKey Data:";cin>>data;	s.search(data);goto xx;
		case 5:s.rev();goto xx;
		case 6:s.swap();goto xx;
		default : return 0;
	}
}
                                                                                                                                             
