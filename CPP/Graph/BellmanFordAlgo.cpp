// Bellman Ford Algorithm
// Used to compute shorted path with negatice edges
// Helps to detect negatice cycles
// Time Complexity: O(V*E) (Quadritic Time Complexity)
#include <iostream>
#include <vector>
using namespace std;
class Graph {
    private:
    vector<vector<pair<int, int>>>adj;
    vector<vector<int>>edges;
    int v;
    public:
    Graph(int x) {
        this->v = x;
        adj.resize(v);
    }
    void addEdge(int v, int e, int w) {
        adj[v].push_back({e, w});
    }
    void adjToEdges(int e) {
        edges.resize(e, vector<int>(3));
        int ptr = 0;
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                edges[ptr][0] = i;      
                edges[ptr][1] = it.first;
                edges[ptr][2] = it.second;
                ptr++;
            }
        }
    }
    vector<int> bellmanFord(int S);
};

vector<int>Graph :: bellmanFord(int S) {
    vector<int>dist(v, 1e9);
    dist[S] = 0;

    // Performing Relax operation v-1 times:
    for(int i=0; i<v-1; i++) {
        for(auto it : edges) {
            int v = it[0];
            int e = it[1];
            int wt = it[2];
            if(dist[v]!=1e9 && dist[e] > dist[v] + wt)
                dist[e] = dist[v] + wt;
        }
    }

    // Checking For negative-weight cycle;
    for(int i=0; i<edges.size(); i++) {
        int v = edges[i][0];
        int e = edges[i][1];
        int wt = edges[i][2];
        if(dist[v]!=1e9 && dist[e] > dist[v] + wt){
            cout << "Graph contain negative weight cycle: ";
            return {-1};
        }
    }
    cout << "Shortest distance from source to every node: ";
    return dist;

}
int main() {
    int v, e, S;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    Graph g1(v);
    cout << "Enter edges with weight: ";
    for(int i=0; i<e; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g1.addEdge(x, y, z);
    }
    g1.adjToEdges(e);
    // Implementing Bellman Ford
    cout << "Enter source node: ";
    cin >> S;
    vector<int>dist = g1.bellmanFord(S);
    for(int i=0; i<v; i++) {
        cout << dist[i] << " ";
    }
}