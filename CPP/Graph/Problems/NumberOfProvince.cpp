// Number of Province
#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& adj, int s, vector<bool>& visited) {
    visited[s] = true;
    for(auto it : adj[s]) {
        if(!visited[it])
            dfs(adj, it, visited);
    }
}
int numberOfProvince(vector<vector<int>>& adj, int v) {
    int count = 0;
    vector<bool>visited(v, false);
    for(int i=0; i<v; i++){
        if(!visited[i]){
            count++;
            dfs(adj, i, visited);
        }
    }
    return count;
}
int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<int>>adj(v);
    cout << "Enter edges: ";
    for(int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << numberOfProvince(adj, v);
}