// Shortest path in undirected graph
#include <iostream>
#include <climits>

using namespace std;

#define V 8

int mindist(int G[V][V], int src, int dst, bool visited[], int parent[])
{
    //Base Conditions
    if(src == dst)
        return 0;
        
    visited[src] = true;
        
    int min_dist = INT_MAX;
    
    for(int k = 0; k < V; k++)
    {
        if(visited[k] == false && G[src][k])
        {
            int res = mindist(G, k, dst, visited, parent);
            if(res != INT_MAX)
            {
                if(min_dist > G[src][k] + res)
                {
                    min_dist = G[src][k] + res;
                    parent[k] = src;
                }
            }
        }
    }
    
    visited[src] = false;
    
    return min_dist;
}

void printpath(int parent[], int dst)
{
    if(parent[dst] == -1)
        return;
        
    printpath(parent, parent[dst]);
    
    cout << parent[dst] << "-->";
}

int main()
{
    int G[V][V] = { { 0, 1, 2, 5, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 4, 11, 0, 0 },
                    { 0, 0, 0, 0, 9, 5, 16, 0 },
                    { 0, 0, 0, 0, 0, 0, 2, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 18 },
                    { 0, 0, 0, 0, 0, 0, 0, 13 },
                    { 0, 0, 0, 0, 0, 0, 0, 2 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 }
                  };
                  
    bool visited[V];
    int parent[V];
    
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
    
    cout << " Min Distance from 0 to 7 : " << mindist(G, 0, 7, visited, parent) << endl;
    
    cout << "Path : ";
    
    printpath(parent, 7);
    
    cout << "7" << endl;
    
    return 0;
}
