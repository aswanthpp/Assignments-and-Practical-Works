#include<stdio.h>
#include<string.h>
#include<math.h>
int *conv(int);
main()
{	int a[4],b[4],i,d,e=0,t=1,u=1,ac[4],bc[4],*d1,*d2;
	printf("\nEnter a Decimal Digit[0-9] :");
	scanf("%d",&d);
	if(d<5)
	{	d1=conv(d);
		a[0]=0;
		for(i=1;i>=0;i--)
		{	a[t]=*(d1+i);
			t++;
		}
		for(i=0;i<4;i++)
		{	if(a[i]==0)
			ac[i]=1;
			else 
			ac[i]=0;
		}
		printf("\n2421 Code:");
		for(i=0;i<4;i++)
		printf("%d",a[i]);
		printf("\nComplement:");
		for(i=0;i<4;i++)
		printf("%d",ac[i]);
		for(i=3;i>=1;i--)
		e+=ac[i]*pow(2,(3-i));
		printf("\n%d",e+2);
	}
	else
	{	d2=conv(d-2);
		for(i=2;i>=0;i--)
		b[u++]=*(d2+i);
		for(i=0;i<4;i++)
		{	if(b[i]==0)
			bc[i]=1;
			else
			bc[i]=0;
		}
		printf("\n2421 Code");
		for(i=0;i<4;i++)
		printf("%d",b[i]);
		printf("\nComplement:");
		for(i=0;i<4;i++)
		printf("%d",bc[i]);
		for(i=3;i>=1;i++)
		e+=bc[i]*pow(2,(3-i));
		printf("\n%d",e);
	}
}
int *conv(int d)
{	int n[4],t=0;
	while(d>0)
	{	n[t]=d%2;
		d/=2;
		t++;
	}
	while(t<3)
	{	n[t]=0;
		t++;
	}
	return n;
}	
