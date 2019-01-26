// Edge to be deleted such that subtree sum difference is minimum
#include <iostream> 
#include <climits>
#include <vector> 

using namespace std; 

#define V 7
#define min(a, b) (a < b ? a : b)

int dfs(int g[][V], int src, bool visited[], int wt[V])
{
    int total  = 0;
    
    visited[src] = true;
    
    for(int i = 0; i < V; i++)
    {
        if(visited[i] == false && g[src][i])
            total += dfs(g, i, visited, wt);
    }
    
    visited[src] = false;
    
    return total + wt[src];
}

int minval = INT_MAX;
int a, b;

int mindiff(int g[][V], int src, int total, bool visited[], int wt[])
{
    int sum = 0, subtree_sum = 0;
    
    visited[src] = true;
    
    for(int i = 0; i < V; i++)
    {
        if(visited[i] == false && g[src][i])
        {
            sum = mindiff(g, i, total, visited, wt);
            // Update the edges which gives mindifference when an edge is removed
            if(minval > (total - sum) - sum)
            {
                a = src;
                b = i;
                minval = min(minval, (total - sum) - (sum));
            }
            subtree_sum += sum;
        }
    }
    
    return subtree_sum + wt[src];
}

int main()
{
    int g[V][V] = { { 0, 1, 1, 1, 0, 0, 0 },
                   { 1, 0, 0, 0, 0, 0, 0 },
                   { 1, 0, 0, 0, 1, 1, 0 },
                   { 1, 0, 0, 0, 0, 0, 1 },
                   { 0, 0, 1, 0, 0, 0, 0 },
                   { 0, 0, 1, 0, 0, 0, 0 },
                   { 0, 0, 0, 1, 0, 0, 0 }
                };
                
    int total = 0;
    int wt[V] = { 4, 2, 1, 6, 3, 5, 2};
    
    bool visited[V] = { false };
    
    //Calculate total weight of the graph
    for(int i = 0; i < V; i++)
        total += wt[i];
    
    cout << "Total value of graph :" << total << endl;
    
    mindiff(g, 0, total, visited, wt);
    
    cout << "Edges :" << a << "<--->" << b << endl;
    cout << "Min Diff after edge is removed : " << minval;

    return 0;
}