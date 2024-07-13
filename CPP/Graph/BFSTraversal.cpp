// BFS- Breadth First Search Traversal in Graph
/*
The BFS traversal of Graphs also traverses the graph in levels.
It starts the traversal with a given vertex, visits all of the vertices 
adjacent to the initially given vertex and pushes them all to a queue in order of visiting. Then it pops an element from the front of the queue, visits all of its neighbours and pushes the neighbours which are not already visited into the queue and repeats the process until the queue is empty or all of the vertices are visited.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph{
    private:
    vector<vector<int>>adjList;
    int v;

    public:
    Graph(int x) {
        this->v = x;
        adjList.resize(v);
    }
    void addEdges(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void BFS();
};

void Graph :: BFS() {
    vector<bool>visited(v+1, false);
    queue<int>q;
    int source = 0;
    visited[source] = true;
    q.push(source);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i=0; i<adjList[node].size(); i++) {
            if(visited[adjList[node][i]] == false){
                visited[adjList[node][i]] = true;
                q.push(adjList[node][i]);
            }
        }
    }
}

int main() {
    int v, e;
    cout << "Enter no of vertices: ";
    cin >> v;
    cout << "Enter no of edges: ";
    cin >> e;
    Graph g1(v);
    cout << "Enter edges: ";
    for(int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        g1.addEdges(x, y);
    }
    cout << "BFS Traversal: ";
    g1.BFS();
}
