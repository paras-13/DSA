// Is Bipartite Graph
// In a bipartite graph no two adjacent nodes have same color

// A graph which will have an odd length cycle will always be a bipartite graph
// Using DFS
// TIme Complexity: O(V+E)
#include <iostream>
#include <vector>
using namespace std;
class Graph
{
private:
    vector<vector<int>> adj;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
        adj.resize(v);
    }
    void addEdge(int v, int u)
    {
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    bool isBipartiteGraph();
};

bool dfs(vector<vector<int>> &adj, vector<int> &colors, int s, int col)
{
    colors[s] = col;
    for (auto x : adj[s])
    {
        if (colors[x] == -1)
        {
            if (!dfs(adj, colors, x, !col))
                return false;
        }
        else if (colors[x] == col)
            return false;
    }
    return true;
}
bool Graph ::isBipartiteGraph()
{
    int n = adj.size();
    vector<int> colors(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (colors[i] == -1)
        {
            if (!dfs(adj, colors, i, 0))
                return false;
        }
    }
    return true;
}

int main()
{
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    Graph g1(v);
    cout << "Enter edges: ";
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g1.addEdge(x, y);
    }
    bool isBipartite = g1.isBipartiteGraph();
    if (isBipartite)
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is not Bipartite" << endl;
}