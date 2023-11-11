// BFS - Breadth First Search Algorithm
/*
    -> It starts at the root of the graph and visits all nodes at the current 
       depth level before moving on to the nodes at the next depth level.

    -> Similar to LevelOrder traversal in tree but with some additional condition.

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> v, int sv)
{
    int n = v.size();
    vector<bool> visited(n, false);
    queue <int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty())
    {
        int cv = q.front();
        q.pop();
        cout << cv <<" ";
        for(int i=0; i<n; i++)
        {
            if(v[cv][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

}
int main()
{
    int v, e;
    cin >> v >> e;
    vector <vector<int>> matrix(v, vector<int>(v, 0));
    for(int i=0; i<e; i++)
    {
        int fv, sv;
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }
    bfs(matrix, 0);
    
}
