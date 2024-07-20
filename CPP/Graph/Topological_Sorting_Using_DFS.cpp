// Topological Sorting using DFS
// Time Complexity: O(V+E);
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Graph{
    private:
    vector<vector<int>> adj;
    int v;
    public:
    Graph(int v) {
        this->v = v;
        adj.resize(v);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void DFS(stack<int>&st, vector<bool>&visited, int s);
    stack<int>topoSort();
};

void Graph :: DFS(stack<int>&st, vector<bool>&visited, int s) {
    visited[s] = true;
    for(auto it : adj[s]) {
        if(!visited[it])
            DFS(st, visited, it);
    }
    st.push(s);
}
stack<int>Graph :: topoSort() {
    vector<bool>visited(v+1, false);
    stack<int>st;
    for(int i=0; i<v; i++) {
        if(!visited[i])
            DFS(st, visited, i);
    }
    return st;
}
int main() {
    int v, e;
    cout << "Enter number of vertices: ";
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
    stack<int> res = g1.topoSort();
    cout << "Topological Sorting Using DFS: ";
    while(!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
}