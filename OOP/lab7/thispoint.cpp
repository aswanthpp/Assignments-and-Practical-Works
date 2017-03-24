#include<iostream>
#include<stdio.h>
#include<stdlib.h>

int s=0;
using namespace std;
class Calci
{	private:
		float x,y;
		float s;
		char c;
	public:
		Calci &add(){
				this->s=0;
				this->s=this->x +this->y;
				return *this;
			    }
		Calci &diff(){	this->s=0;
				this->s=this->x- this->y;
				return *this;
			     }
		Calci &mult(){	this->s=0;
				this->s=this->x * this->y;
				return *this;
			     }
		Calci &div(){	this->s=0;
				if(this->y!=0)
				{	
					this->s=this->x / this->y;
					return *this;
				}
				else
				{	cout<<"\n Division By 0 is not Possible \n";
					exit(0);
				}
			     }
		Calci &display(){	cout<<"\nResult: "<<this->s;	
			        }
		Calci &input(){   cout<<"\nEnter Input-1 and Input-2 : ";
				  cin>>this->x>>this->y;
					return *this;
			       }
	
};
main()
{	int x;
	Calci P;
	cout<<"\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division";
	xx: cout<<"\nEnter Option :";
	cin>>x;
	switch(x)
	{	case 1: P.input().add().display();goto xx;
		case 2: P.input().diff().display();goto xx;
		case 3: P.input().mult().display();goto xx;
		case 4: P.input().div().display();goto xx;
		default: return 0;
	}
	cout<<"\n";
	return 0;
}


