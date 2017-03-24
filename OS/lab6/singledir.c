#include<stdio.h>
main()
{
int master,s[20];
char f[20][20][20];
char d[20][20];
int i,j;
	printf("enter number of main directorios:");
	scanf("%d",&master);
	for(i=0;i<master;i++)
	{	 printf("enter name of directory %d:",i+1);
		 scanf("%s",&d[i]);
	}
	for(i=0;i<master;i++)
	{	printf("enter size of directory %d:",i+1);
		scanf("%d",&s[i]);
	}
		for(i=0;i<master;i++)
		{	printf("\nEnter file names in directory %d",i+1);
			for(j=0;j<s[i];j++)
			{	printf("\nFile name %d:",j+1);
				scanf("%s",&f[i][j]);
			}
			
		}
	printf("\n");
	printf(" directory\tsize\tfilenames\n");
	printf("_______________________________________\n");
	for(i=0;i<master;i++)
	{	printf("%s\t\t%2d\t",d[i],s[i]);
		for(j=0;j<s[i];j++)
		printf("%s\n\t\t\t",f[i][j]);
		printf("\n");
	}
	printf("\n");
}

