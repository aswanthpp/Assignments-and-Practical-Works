// Implement DFS 
//
//
#include<stdio.h>
int a[20][20],i,j,n,visited[20],x,v;
void dfs(int v);
void insert()
{
int v;
 printf("\n Enter the number of vertices:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  visited[i]=0;
 }

 printf("\n Enter graph data in matrix form:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
{       if(i>=j)
                continue;
        printf("\nV%d-V%d is an edge [1 or 0] :",i,j);
        scanf("%d",&x);
        if(x!=0)
        {       a[i][j]=1;
                a[j][i]=1;}
        else
        {       a[i][j]=0;}
}
printf("\nAdjacency Matrix:\n");
for(i=1;i<=n;i++)
{       printf("\n");
        for(j=1;j<=n;j++)
                printf("%d ",a[i][j]);
}
 printf("\n Enter the starting vertex:");
 scanf("%d",&v);
printf("DFS=");
 dfs(v);
printf("\n");

}
void dfs(int v)
{	int j;
	printf("%d ",v);
	visited[v]=1;
	for(j=1;j<=n;j++)
	if(!visited[j]&&a[v][j])
		dfs(j);
}
void main()
{	insert();
}
	
