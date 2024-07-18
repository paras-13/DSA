// Cycle Detection in a Directed Graph:
// Using DFS
// Time Complexity: O(V+E)
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
    }
    bool isCyclic();
    bool DFS(vector<bool>&visited, vector<bool>&ancestor, int s);

};
bool Graph :: DFS(vector<bool>&visited, vector<bool>&ancestor, int s) {
    visited[s] = true;
    ancestor[s] = true;
    for(auto it : adjList[s]) {
        if(!visited[it]) {
            if(DFS(visited, ancestor, it))
                return true;
        }
        if(ancestor[it])
            return true;
    }
    ancestor[s] = false;
    return false;
}
bool Graph :: isCyclic() {
    vector<bool>visited(v+1, false);
    vector<bool>ancestor(v+1, false);
    for(int i=0; i<v; i++) {
        if(!visited[i])
            if(DFS(visited, ancestor, i))
                return true;
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