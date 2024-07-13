// DFS - Depth First Search Algorithm
/*
    Depth-first search is an algorithm for traversing or searching tree or graph data structures.
    The algorithm starts at the root node (selecting some arbitrary node as the root node in the 
    case of a graph) and explores as far as possible along each branch before backtracking.
*/
#include <iostream>
#include <vector>
using namespace std;
class Graph{
    private:
    vector<vector<int>>adjList;
    int V;
    public:
    Graph(int v) {
        this->V = v;
        adjList.resize(V);
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void DFS(int s);
    void DFSRec(int s, vector<bool>&visited);
};
void Graph :: DFSRec(int s, vector<bool> &visited) {
    visited[s] = true;
    cout << s << " ";
    for(int i : adjList[s]) {
        if(visited[i] == false)
            DFSRec(i, visited);
    }
}
void Graph :: DFS(int s) {
    vector<bool>visited(V+1, false);
    DFSRec(s, visited);
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
    g1.DFS(0);
}