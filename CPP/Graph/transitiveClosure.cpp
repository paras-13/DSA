// Transitive Closure in a graph
// Problem => To determine whether a vertex j is reachable from another vertex i for all vertex pairs(i, j) in the given graph
// this code is for directed edge weight, but can also be used for undirected edge weight, but just including the opposite edge
#include <bits/stdc++.h>
#define P pair<int, int>
using namespace std;
class Graph
{
private:
    int V;
    vector<vector<P>> adj;
    vector<vector<int>> dist;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
        dist.resize(V, vector<int>(V, 0));
    }
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
    }
    vector<vector<int>> transitiveClosure()
    {
        for (int u = 0; u < V; u++)
        {
            dist[u][u] = 1;
            for (auto [v, w] : adj[u])
            {
                dist[u][v] = 1; // 1 is to mark that their is path from a to b;
            }
        }

        // Now just using simple floyd algo to check whether path exist or not using bit
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (dist[i][j] | (dist[i][k] & dist[k][j]))
                        dist[i][j] = 1;
                }
            }
        }
        return dist;
    }
};
int main()
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    Graph g1(n);
    cout << "Enter directed edge weights: ";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g1.addEdge(u, v, w);
    }
    vector<vector<int>> res = g1.transitiveClosure();
    cout << "Trnsitive Closure: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nodes connected with " << i << ": ";
        for (int j = 0; j < n; j++)
        {
            if (res[i][j] == 1)
                cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}