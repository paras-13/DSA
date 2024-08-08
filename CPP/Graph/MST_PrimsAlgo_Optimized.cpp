// Finding Minimum Spanning Tree (MST) using Prims Algo
// Optimized approach using heap
// Time Complexity: (ElogV)
// Mainting two additional vector one to track visited node and other two store mst edges:
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
class Graph {
    private:
    vector<vector<pair<int, int>>> adj;
    vector<pair<int, int>>MST;
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
    int spanningTree();
    void printMST();
};

int Graph :: spanningTree() {
    int sum= 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<bool>isMST(v, false);
    //  {Weight, node, parent};
    pq.push({0, 0, -1});
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it[0];
        int node = it[1];
        int parent = it[2];
        if(isMST[node])
            continue;
        isMST[node] = true;
        sum += wt;
        if(parent!=-1) {
            MST.push_back({parent, node});
        }
        for(auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;
            if(!isMST[adjNode])
                pq.push({weight, adjNode, node});
        }
    }
    return sum;
}

void Graph :: printMST() {
    cout << endl << "Printing Minimum Spanning Tree: " << endl;
    for(auto it : MST){
        cout << it.first << " -> " << it.second << endl;
    }
}

int main() {
    int v,e;
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
    cout << "Sum of weight of edges of MST: " << g1.spanningTree();
    g1.printMST();
}   
