/*
    Kruskal's Algorithm for Minimum Spanning Tree (MST)

    Description:
    Kruskal's algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST)
    of a connected, undirected, and weighted graph. It works by sorting all the edges in
    non-decreasing order of their weights and then adding them one by one to the MST,
    ensuring that no cycle is formed (using Disjoint Set Union - DSU).

    Time Complexity:
        O(E log E + E * α(V))
        - E log E for sorting the edges
        - E * α(V) for union-find operations (α is the inverse Ackermann function, nearly constant)

    Space Complexity:
        O(V + E)
        - O(V) for DSU structures
        - O(E) for storing edges

    Where:
        V = Number of vertices
        E = Number of edges
*/

// Kruskal Minimum Spanning Tree
// Using DSU

#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    bool unionBySize(int u, int v)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if (parentU == parentV)
            return false;
        else if (size[parentU] >= size[parentV])
        {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
        else
        {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        return true;
    }
};
class Graph
{
private:
    int v;
    vector<vector<int>> edges;

public:
    Graph(int n) : v(n) {}
    void addEdge(int u, int v, int w)
    {
        edges.push_back({u, v, w});
    }
    void sortEdges()
    {
        sort(edges.begin(), edges.end(), [&](vector<int> v1, vector<int> v2)
             { return v1[2] < v2[2]; });
    }
    int kruskal()
    {
        DisjointSet ds(v);
        int mst = 0;
        for (auto edge : edges)
        {
            if (ds.unionBySize(edge[0], edge[1]))
            {
                mst += edge[2];
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
    cout << "Enter number  of edges: ";
    cin >> m;
    Graph g1(n);
    cout << "Enter undirected weighted edges: ";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g1.addEdge(u, v, w);
    }
    g1.sortEdges();
    int mst = g1.kruskal();
    cout << mst << endl;
    return 0;
}