// DFS Traversal for Disconnected Graph
#include <iostream>
#include <vector>
using namespace std;
class Graph {
    private:
    vector<vector<int>> adjList;
    int v;
    public:
    Graph(int v) {
        this->v = v;
        adjList.resize(v);
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void DFS();
    void DFSRec(vector<bool>&visited, int i);
};

void Graph :: DFS() {
    vector<bool>visited(v+1, false);
    for(int i=0; i<v; i++) {
        if(visited[i] == false)
            DFSRec(visited, i);
    }
}

void Graph :: DFSRec(vector<bool>&visited, int i) {
    visited[i] = true;
    cout << i << " ";
    for(auto x : adjList[i]){
        if(!visited[x])
            DFSRec(visited, x);
    }
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
    g1.DFS();
}