// Adjacency List representation:
#include <iostream>
#include <vector>
using namespace std;
class Graph{
    private:
    vector<int>adjList[10];
    int v;
    public:
    Graph(int v) {
        this->v = v;
        adjList[v];
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void print(){
        cout << "Adjacency List: " << endl;
        for(int i=0; i<v; i++) {
            cout << i << ": ";
            for(auto x : adjList[i])
                cout << "->" << x ;
            cout << endl; 
        }
    }
};

int main() {
    int v, e;
    cout << "Enter no of vertex: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edge between vertices (u v): " << endl;
    Graph g1(v);
    for(int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        g1.addEdge(u, v);
    }
    g1.print();
}