// Shortest Path in a Directed Acyclic Graph: 
// Time Complexity :- TopoSort=O(V+E); shortPath:- O(V+E) , Net = O(V+E);
#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
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
    }
    stack<int> getTopoSort();
    void DFS(stack<int>&st, vector<bool>&visited, int s);
    vector<int> shortestPathInDAG(stack<int>&st, int s);
};

void Graph :: DFS(stack<int>&st, vector<bool>&visited, int s) {
    visited[s] = true;
    for(auto it : adj[s]) {
        if(!visited[it.first])
            DFS(st, visited, it.first);
    }
    st.push(s);
}
stack<int> Graph ::  getTopoSort() {
    stack<int>st;
    vector<bool>visited(v+1, false);
    for(int i=0; i<v; i++){
        if(!visited[i])
            DFS(st, visited, i);
    }
    return st;
}

vector<int> Graph :: shortestPathInDAG(stack<int>&st, int s){
    vector<int>distance(v, INT_MAX);
    distance[s] = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(distance[node]!=INT_MAX) {
            for(auto it : adj[node]) {
                int v = it.first;
                int w = it.second;
                distance[v] = min(distance[v], distance[node] + w);
            }
        }
    }
    return distance;
}
int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    Graph g1(v);
    cout << "Enter edges with weight: ";
    for(int i=0; i<e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g1.addEdge(x, y, w);
    }
    stack<int>st = g1.getTopoSort();
    int s;
    cout << "Enter souce: ";
    cin >> s;
    vector<int>distance = g1.shortestPathInDAG(st, s);
    cout << "Minimum cost path: ";
    for(int i=0; i<distance.size(); i++) {
        if(distance[i] == INT_MAX) cout << -1 << " ";
        else
            cout << distance[i] << " ";
    }
}