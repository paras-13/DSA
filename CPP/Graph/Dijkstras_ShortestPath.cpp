// Dijkstra's Shortest Path Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
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
    void addEdge(int v, int e, int w) {
        adj[v].push_back({e, w});
        adj[e].push_back({v, w});
    }
    vector<int> shortestPathDijkstra(int s);
};

vector<int> Graph :: shortestPathDijkstra(int s) {
    vector<int>dist(v, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, s});
    // {weight, edgeNode}
    dist[s] = 0;
    while(!pq.empty()) {
        auto itr = pq.top();
        pq.pop();
        int wt = itr.first;
        int node = itr.second;
        for(auto it : adj[node]){
            int adjNode = it.first;
            int weight = it.second;
            if(dist[adjNode] > wt + weight){
                dist[adjNode] = wt + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main() {
    int v, e, s;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    Graph g1(v);
    cout << "Enter edges with weight: " << endl;
    for(int i=0; i<e; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g1.addEdge(x, y, z);
    }
    cout << "Enter source node to start from: ";
    cin >> s;
    vector<int>dist = g1.shortestPathDijkstra(s);
    for(int i=0; i<v; i++)
        cout << dist[i] << " ";
}