// Implement tree using array
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void preorder(int i,int a[]);
void postorder(int i,int a[]);
void inorder(int i,int a[]);

main()
{	int h,n,i,f,data;
	printf("\nEnter Height of the Tree:");
	scanf("%d",&h);
	n=pow(2,h+1)-1;
	int a[h];
	for(i=0;i<n;i++)a[i]=-1;
	printf("\nEnter Root :");
	scanf("%d",&a[0]);
	printf("\n1.Insert New Node\n2.Preorder\n3.Postorder\n4.Inorder\n5.Exit");
	do
	{	printf("\nEnter Option:");
		scanf("%d",&n);
		if(n==1)
		{	 printf("\nEnter Data:");
				scanf("%d",&data);i=0;
				while(1)
				{	
				printf("\n1.Left\t2.Right Option:");
       				 scanf("%d",&f);
                			i=2*i+f;
                			if(a[i]==-1)
                			{       a[i]=data;
                       				 break;
                			}
				}
		}
		else if(n==2)
			preorder(0,a);
					
		else if(n==3)
			postorder(0,a);
				
		else if(n==4)
			inorder(0,a);
		else exit(0);
		
	}while(1);
}
void preorder(int i,int a[])
{	if(a[i]!=-1)
	{	printf("%d ",a[i]);
		preorder(2*i+1,a);
		preorder(2*i+2,a);
	}
}
void postorder(int i,int a[])
{       if(a[i]!=-1)
        {       
                postorder(2*i+1,a);
                postorder(2*i+2,a);
		printf("%d ",a[i]);
        }
}
void inorder(int i,int a[])
{       if(a[i]!=-1)
        {       
                inorder(2*i+1,a);
		printf("%d ",a[i]);
                inorder(2*i+2,a);
        }
}

