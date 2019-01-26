// Minimum edges to be reversed from Source to Destinaton 
#include <iostream>
#include <climits>

using namespace std;

#define V 7

#define min(a, b) ((a < b) ? a : b)

int dfs(bool g[][V], int src, int dst, bool visited[], bool directed[][V])
{
    int count = INT_MAX, result = INT_MAX;
    
    if(src == dst)
        return 0;
        
    visited[src] = true;
    
    for(int u = 0; u < V; u++)
    {
        if(g[src][u] == true  && visited[u] == false)
        {
            result = dfs(g, u, dst, visited, directed);
            if(result != INT_MAX)
                count = min(count, result + directed[u][src]);
        }
    }
    
    visited[src] = false;
    
    return count;
}

int main()
{
#if 0
        // Prints 0 as answer, as there is direct path from source to destination
        bool directed[][V] = { { 0, 1, 0, 0, 0, 0, 0 },
                               { 0, 0, 1, 0, 0, 0, 0 },
                               { 0, 0, 0, 1, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 1 },
                               { 0, 0, 0, 0, 0, 1, 0 },
                               { 0, 1, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 1, 0, 0 }
                            };
#endif

#if 1
        // Prints 3 as answer, since reversing min 3 edges gets from source to destination
        bool directed[][V] = { { 0, 1, 0, 0, 0, 0, 0 },
                               { 0, 0, 1, 0, 0, 0, 0 },
                               { 0, 1, 0, 0, 0, 0, 0 },
                               { 0, 0, 1, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 1, 0 },
                               { 0, 1, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 1, 1, 0, 0 }
                            };
#endif

#if 0
        // Prints 2 as answer, since reversing min 2 edges gets from source to destination
        bool directed[][V] = { { 0, 1, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 0 },
                               { 0, 1, 0, 1, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 1, 0 },
                               { 0, 1, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 1, 1, 0, 0 }
                            };
#endif
             
        bool g[V][V];
        int i, j;
        bool visited[V];
        
        // Update all the edges as undirected by using directed graph        
        for(i = 0; i < V; i++)
        {
            visited[i] = false;
            for(j = 0; j < V; j++)
            {
                g[i][j] = 0;
                if(directed[i][j])
                {
                    g[i][j] = 1;
                    g[j][i] = 1;
                }
            }
        }
        
        printf(" Minimum edges to be reversed to reach destination : %d  \n", dfs(g, 0, 6, visited, directed));
        
        return 0;
}