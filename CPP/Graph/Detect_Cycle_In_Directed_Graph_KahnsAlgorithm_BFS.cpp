// Using Kahn's Algorithm(BFS) to detect cycle in an undirected graph
// Time Complexity: O(V+E);
#include <iostream>
#include <vector>
#include <queue>
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
    public:
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    bool detectCycle();
};
bool Graph :: detectCycle() {
    vector<int>indegree(v);
    for(int i=0; i<v; i++) {
        for(auto it : adj[i])
            indegree[it]++;
    }

    queue<int>q;
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    return (count!=v);
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
    if(g1.detectCycle())
        cout << "Cycle Exist";
    else
        cout << "No Cycle";
}