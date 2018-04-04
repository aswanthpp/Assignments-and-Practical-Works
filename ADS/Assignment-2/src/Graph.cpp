#include "Graph.h"
#include "BinaryHeap.cpp"
#include "BinomialHeap.cpp"
#include "FibonacciHeap.cpp"

# define INF 0x3f3f3f3f

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int> > [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::generateMST(int heap_type)
{
    Heap *heap;

    switch(heap_type)
    {
        case BINARY: heap = new BinaryHeap(); break;
        case BINOMIAL: heap = new BinomialHeap(); break;
        case FIBONACCI: heap = new FibonacciHeap(); break;
    }

    vector<int> key(V, INF);
    vector<int> parent(V);
    vector<bool> mstSet(V, false);

    (*heap).push(make_pair(0, 0));

    key[0] = 0;
    parent[0] = -1;

    while ((*heap).top() != make_pair(-1, -1))
    {
        int u = (*heap).top().second;
        (*heap).pop();

        mstSet[u] = true;

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            
            if(mstSet[v] == false && weight<key[v])
            {
                parent[v] = u;
                key[v] = weight;
                (*heap).push(make_pair(key[v], v)); 
            }
        }
    }

    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
    {   list< pair<int, int> >::iterator j;
        int min = INT_MAX;
        for (j = adj[i].begin(); j != adj[i].end(); ++j){
             if((*j).second<min)
             min = (*j).second; 
        }
        printf("%d - %d   %d\n", parent[i], i, min);
    }

    printf("\nNumber of Operations performed : %d \n", (*heap).getOperations());
    return;
}
