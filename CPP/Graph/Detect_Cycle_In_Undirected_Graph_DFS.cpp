// Detected Cycle in an undirected Graph:
// Using DFS Traversal
// Time Complexity: O(V+E);

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    vector<vector<int>> adjList;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
        adjList.resize(v);
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bool DFS(vector<bool>&visited, int s, int parent);
    bool isCyclic();
};

bool Graph :: DFS(vector<bool>&visited, int s, int parent) {
    visited[s] = true;
    for(auto it : adjList[s]){
        if(!visited[it]) {
            if(DFS(visited, it, s))
                return true;
        }
        else if(parent != it)
            return true;
    }
    return false;
}
bool Graph :: isCyclic() {
    vector<bool>visited(v+1, false);
    for(int i=0; i<v; i++) {
        if(!visited[i]){
            if(DFS(visited, i, -1))
                return true;
        }
    }
    return false;
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
    if(g1.isCyclic())
        cout << "Cycle Exists";
    else 
        cout << "No Cycle";
}