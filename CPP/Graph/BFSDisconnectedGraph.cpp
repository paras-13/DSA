// BFS Algorithm for disconnected graph and unknown starting source:
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph{
    private:
    vector<vector<int>>adjList;
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
    void BFS();
    void BFSDis(vector<bool>&visited, int i);
};
void Graph ::BFS() {
    vector<bool>visited(v+1, false);
    for(int i=0; i<v; i++) {
        if(visited[i] == false)
            BFSDis(visited, i);
    }
}
void Graph::BFSDis(vector<bool>&visited, int i) {
    queue<int>q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int j=0; j<adjList[node].size(); j++) {
            if(visited[(adjList[node][j])] == false){
                visited[(adjList[node][j])] = true; 
                q.push(adjList[node][j]);
            }
        }
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
    g1.BFS();
}