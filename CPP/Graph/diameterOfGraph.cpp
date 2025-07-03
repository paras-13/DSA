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
    int findDiameter();
    pair<int, int> dfs(int src, int parent);
};

int Graph ::findDiameter()
{
    auto d1 = dfs(1, -1);
    auto d2 = dfs(d1.first, -1);
    return d2.first;
}
pair<int, int> Graph ::dfs(int src, int parent)
{
    pair<int, int> res = {0, src};
    for (int it : adj[src])
    {
        if (it == parent)
            continue;
        auto temp = dfs(it, src);
        temp.first++;
        res = max(res, temp);
    }
    return res;
}
int main()
{
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    Graph *g1 = new Graph(v);
    for (int i = 0; i < e; i++)
    {
        int p, q;
        cin >> p >> q;
        g1->addEdge(p, q);
    }
    int diameter = g1->findDiameter();
    cout << "Diameter of graph: " << diameter;
    return 0;
}