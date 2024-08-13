// Kosaraju Algorithm (SCC) Strongly Conncted Componnent
// Time Complexity: 
/*
Step1 : TopoSort = O(V+E)
Step2 : AdjList Reverse = O(V+E)
Step 3 : DFS() = O(V+E);
Total Time Complexity:- O(V+E)
*/
// Space := O(V+E);
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Class Graph
class Graph {
private:
    vector<vector<int>> adj;
    int v;

public:
    Graph(int v) {
        this->v = v;
        adj.resize(v);
    }

    void addEdge(int v, int u) {
        adj[v].push_back(u);
    }

    int kosaraju();
    void topoSort(vector<bool>& visited, int node, stack<int>& st);
};

void Graph::topoSort(vector<bool>& visited, int node, stack<int>& st) {
    visited[node] = true;
    for (auto it : adj[node]) {
        if (!visited[it])
            topoSort(visited, it, st);
    }
    st.push(node);
}

void DFS(vector<bool>& visited, int node, vector<int> adjR[]) {
    visited[node] = true;
    cout << node << " ";
    for (auto it : adjR[node]) {
        if (!visited[it]) {
            DFS(visited, it, adjR);
        }
    }
}

int Graph::kosaraju() {
    // Step 1 --> To get Topo Sort
    stack<int> st;
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            topoSort(visited, i, st);
    }

    // Step 2 --> Reverse adjList
    vector<int> adjR[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false; // To again mark visited array as false
        for (auto it : adj[i])
            adjR[it].push_back(i);
    }

    // Step 3 --> DFS according to finishing time in stack
    int totalComponents = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            totalComponents++;
            DFS(visited, node, adjR);
            cout << endl;
        }
    }
    return totalComponents;
}

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    Graph g1(v);
    cout << "Enter edges: ";
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        g1.addEdge(x, y);
    }
    int totalComponents = g1.kosaraju();
    cout << "Total SSC: " << totalComponents;
    return 0;
}
