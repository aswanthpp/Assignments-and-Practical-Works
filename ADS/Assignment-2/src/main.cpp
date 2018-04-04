#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Graph.cpp"

using namespace std;

int main()
{
    int V,E;
    int u,v,w;	
    int start,stop;
    FILE *inp=fopen("input.txt","r");
    fscanf(inp,"%d",&V);
    fscanf(inp,"%d",&E);
    start=clock();
    Graph g(V); 
    for(int i=0;i<E;i++){
                
        fscanf(inp,"%d",&u);
      	fscanf(inp,"%d",&v);
        fscanf(inp,"%d",&w);
                	
        g.addEdge(u, v, w);	
        }
    stop=clock();
    
    cout<<"---------------------------------------------------------"<<endl;    
    cout<<"|               Input Graph Generated                   |"<<endl;
    cout<<"---------------------------------------------------------"<<endl;     
    cout<<"\nNumber of Vertex : "<<V;
    cout<<"\nNumber of Edges  : "<<E;
    cout<<"\nTime elapsed for graph generation : "<< (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"\n\n";
    
    cout<<"---------------------------------------------------------"<<endl;    
    cout<<"|                      BINARY HEAPS                     |"<<endl;
    cout<<"---------------------------------------------------------"<<endl;    
    start = clock();
    g.generateMST(BINARY);
    stop = clock();
    cout<<"Time elapsed using Binary Heaps: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;
    cout<<"---------------------------------------------------------"<<endl;    
    cout<<"\n\n";
    
    cout<<"---------------------------------------------------------"<<endl;    
    cout<<"|                      BINOMIAL HEAPS                   |"<<endl;
    cout<<"---------------------------------------------------------"<<endl;    
    start = clock();
    g.generateMST(BINOMIAL);
    stop = clock();
    cout << "Time elapsed using Binomial Heaps: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;
    cout<<"---------------------------------------------------------"<<endl;    
    cout<<"\n\n";
    
    cout<<"---------------------------------------------------------"<<endl;    
    cout<<"|                      FIBONACCI HEAPS                  |"<<endl;
    cout<<"---------------------------------------------------------"<<endl;    
    start = clock();
    g.generateMST(FIBONACCI);
    stop = clock();
    cout<< "Time elapsed using Fibonacci Heaps: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;
    cout<<"---------------------------------------------------------"<<endl;    
    cout<<"\n\n";

    return 0;
}

