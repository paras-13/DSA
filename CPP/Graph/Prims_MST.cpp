// MST => Minimum Spanning Tree (Prim's Algo)
// Used in Connected, Undirected and Weighted graphs
// It connects all the vertices with the minimum possible total edge weight, without creating cycles.

// Using Prims Algo
// Time Complexity:- O((E+V)*logV)
// Space : O(E + V)

#include <bits/stdc++.h>
#define P pair<int, int>
using namespace std;
class Graph
{
private:
    int V;
    vector<vector<P>> adj;
    vector<int> isMST;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
        isMST.resize(V, false);
    }
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> MST_Prims()
    {
        vector<int> mst;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto [weight, node] = pq.top();
            pq.pop();
            if (isMST[node])
                continue;
            isMST[node] = true;
            mst.push_back(node);
            for (auto [edge, wt] : adj[node])
            {
                if (!isMST[edge])
                    pq.push({wt, edge});
            }
        }
        return mst;
    }
};

int main()
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    cout << "Enter undirected weighted edges: ";
    Graph g1(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g1.addEdge(u, v, w);
    }
    vector<int> mst = g1.MST_Prims();
    cout << "Minimum Spanning Tree Path => ";
    for (int it : mst)
        cout << it << " ";
    return 0;
}