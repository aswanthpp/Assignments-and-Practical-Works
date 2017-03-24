 // Implement BFS using adjcency matrix
 //
 //
  #include<stdio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1,x;

void bfs(int v)
{

 i=1;
while(i<=n)
{  if(a[v][i] && !visited[i])
 {	 for(j=0;j<=r;j++)
		if(q[j]==i)
	{	
		goto xx;
	}
	q[++r]=i;
}
xx:	i++;
}

 if(f<=r)
 {
  visited[q[f]]=1;
  bfs(q[f++]);
 }
}

void main()
{
 int v;
 printf("\n Enter the number of vertices:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  q[i]=0;
  visited[i]=0;
 }

 printf("\n Enter graph data in matrix form:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
{	if(i>=j)
		continue;
	printf("\nV%d-V%d is an edge [1 or 0] :",i,j);
	scanf("%d",&x);
	if(x!=0)
	{	a[i][j]=1;
		a[j][i]=1;}
	else
	{	a[i][j]=0;}
}
printf("\nAdjacency Matrix:\n");
for(i=1;i<=n;i++)
{	printf("\n");
	for(j=1;j<=n;j++)
		printf("%d ",a[i][j]);
}
 printf("\n Enter the starting vertex:");
 scanf("%d",&v);
	visited[v]=1;
 bfs(v);
printf("\nBFS =%d ",v);
for(i=0;i<n-1;i++)
{	
	if(q[i]!=0)	
	printf("%d ",q[i]);
}
	
 printf("\n The node which are reachable are:");
 for(i=1;i<=n;i++)
  if(visited[i])
   printf("%d\t",i);
//  else
 //  printf("\n %d is not conntected",i);
printf("\n");

 
}
