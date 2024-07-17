// Detect Cycle in Undirected Graph using BFS
// Time Complexity: O(V+E);
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
class Graph {
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
    bool isCyclic();
    bool BFS(vector<bool>&visited, int s);
};
bool Graph :: BFS(vector<bool>&visited, int s) {
    queue<pair<int, int>>q;
    visited[s] = true;
    q.push({s, -1});
    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : adjList[node]) {
            if(!visited[it]){
                visited[it] = true;
                q.push({it, node});
            }
            else if(parent != it)
                return true;
        }
    }
    return false;
}
bool Graph :: isCyclic() {
    vector<bool>visited(v+1, false);
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            if(BFS(visited, i))
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
        cout << "Cycle Exist";
    else
        cout << "No Cycle";
}