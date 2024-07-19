// Topological Sorting for DAG(Directed Acyclic Graph)
// Time Complexity: O(V+E);
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph{
    private:
    vector<vector<int>>adj;
    int v;
    public:
    Graph(int v) {
        this->v = v;
        adj.resize(v);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
   
    vector<int> topologicalSorting();
};

vector<int> Graph :: topologicalSorting() {
    vector<int>indegree(v);
    vector<int>topo;
    for(int i=0; i<v; i++){
        for(auto it : adj[i])
            indegree[it]++;
    }
    queue<int>q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
}
int main() {
    int v, e;
    cout << "Enter umber of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    Graph g1(v);
    cout << "Enter edges: ";
    for(int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        g1.addEdge(x, y);
    }
    vector<int> topo = g1.topologicalSorting();
    cout << "Topological Sort: ";
    for(int i=0; i<v; i++)
        cout << topo[i] << " ";
}
