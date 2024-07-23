// Finding Minimum Spanning Tree(MST) Using Prims Algorithm
// Brute Force Approach
// Time Complexity: O(V^2);
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Graph {
    private:
    vector<vector<pair<int, int>>> adj;
    int v;
    public:
    Graph(int v) {
        this->v = v;
        adj.resize(v);
    }
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int primsMST();
};
int Graph :: primsMST() {
    vector<int> parent(v), key(v, INT_MAX);
    vector<bool> mstSet(v, false);
}
int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    Graph g1(v);
    cout << "Enter edges with weight: ";
    for(int i=0; i<v; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g1.addEdge(x, y, z);
    }
}
