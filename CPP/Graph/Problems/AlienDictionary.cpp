// Alien Dictionary
// GFG --> https://www.geeksforgeeks.org/problems/alien-dictionary/1
/*
    Time Complexity: O(n * |s| + k)
    Space : O(k)
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
string topoSort(vector<int>adj[], int v) {
    // indegree of the element whose order in minimum in the dictionary will be zero and as the order of elements will increase in the dictionary there indegree will also increase hence topoSort is used to traverse over DAG
    vector<int>indegree(v, 0);
    string alienOrder;
    queue<int>q;

    // Calculating indegree of elements
    for(int node=0; node<v; node++) {
        for(auto it : adj[node])
            indegree[node]++;
    }

    //Pushing elements with zero indegree in queue;
    for(int node=0; node<v; node++) {
        if(indegree[node] == 0)
            q.push(node);
    }

    // Traversing
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        char ch = node + 'a';
        alienOrder.push_back(ch);
        for(auto it : adj[node]) {
            indegree[node]--;
            if(indegree[node] == 0)
                q.push(node);
        }
    }
    return alienOrder;
}
string findOrder(vector<string> dict, int n, int k) {
    // N here is the size of array
    // k here is the disticnt alphabets in the dictionary

    // Creating DAG
    vector<int>adj[k];
    for(int i=0; i<n-1; i++) {
        string first = dict[i];
        string second = dict[i+1];
        int limit = min(first.length(), second.length());
        for(int j=0; j<limit; j++) {
            if(first[j] != second[j]){
                int v = first[j] - 'a';
                int e = second[j] - 'a';
                adj[v].push_back(e);
                break;
            }
        }
    }

    string alienOrder = topoSort(adj, k);
    return alienOrder;
}
int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;
    vector<string>dict(n);
    cout << "Enter dictionary elements in sorted alien order: ";
    for(int i=0; i<n; i++)
        cin >> dict[i];
    cout << "Order of characters in the alien dictionary is: ";
    string alienOrder = findOrder(dict, k, n);
    for(int i=0; i<k; i++)
        cout << alienOrder[i] << " ";
    cout << endl;
    return 0;
}
