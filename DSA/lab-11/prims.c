#include<stdio.h>
int u,v,n,i,j,ne=1,f; 
int visited[10]={0},min,mincost=0,cost[10][10]; 
void main()
{
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{	if(i>=j)
			continue;
		printf("\nEnter cost of v%d->v%d :",i,j);
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
			cost[i][j]=999;
		cost[j][i]=cost[i][j];
	}
	printf("\nStarting source:");
	scanf("%d",&f);
	visited[f]=1;
	printf("\nMST Edges are:\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		for(j=1;j<=n;j++)
		if(cost[i][j]< min)
		if(visited[i]!=0)
		{
			min=cost[i][j];
			u=i;
			v=j;
		}
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\n%d. v%d->v%d cost:%d",ne++,u,v,min);
			mincost+=min;
			visited[v]=1;
		}
		cost[u][v]=cost[v][u]=999;
	}
	printf("\nMinimun cost=%d\n",mincost);
}

 
