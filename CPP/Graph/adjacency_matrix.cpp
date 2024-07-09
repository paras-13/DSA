// Adjacency Matrix Representation Of Graph
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    private:
    vector<vector<int>> adjMatrix;

    public:
    Graph(int v) {
        adjMatrix.resize(v+1, vector<int>(v+1, 0));
    }
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;    
    }
    void print() {
        cout << "Adjacency Matrix: " << endl;
        for(int i=0; i<adjMatrix.size(); i++) {
            for(int j=0; j<adjMatrix[i].size(); j++) 
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    Graph g1(v);

    cout << "Enter edge between vertices (u v): " << endl;
    for(int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        g1.addEdge(u, v);
    }
    g1.print();
}