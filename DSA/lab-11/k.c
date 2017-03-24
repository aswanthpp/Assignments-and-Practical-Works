#include<stdio.h>
#include<stdlib.h>
struct egde
{	int a,b,cost;
};
struct graph
{	int e,v;
	struct edge *next;
};
struct graph* creategraph(int v,int e)
{	struct graph* graph=(struct graph*)malloc(sizeof(struct graph));
graph->v=v;
graph->e=e;
graph->edge(struct edge*)malloc(graph->e*sizeof(struct edge))l
return graph;
}

