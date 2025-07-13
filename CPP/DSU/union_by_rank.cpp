/*
    Time Complexity Analysis:

    - The findParent function uses path compression, and unionByRank uses union by rank.
    - With both optimizations, the amortized time per operation (find or union) is O(α(n)),
      where α(n) is the inverse Ackermann function.

    What is O(α(n))?
    - α(n) (inverse Ackermann function) grows extremely slowly.
    - For all reasonable values of n (even up to billions), α(n) ≤ 4.
    - This means that, in practice, each operation is almost constant time.

    Summary:
    - Any sequence of m operations on n elements takes O(m * α(n)) time.
    - For practical purposes, this is considered nearly O(1) per operation.
*/

// Union By rank
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // * To find ultimate parents
    int findParent(int node) {
        if (node == parent[node])
            return node;
        //* path Compression
        return parent[node] = findParent(parent[node]); 
    }

    void unionByRank(int u, int v)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if (parentU == parentV)
            return;
        if (rank[parentU] < rank[parentV])
            parent[parentU] = parentV;
        else if (rank[parentV] < rank[parentU])
            parent[parentV] = parentU;
        else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Check for whether 3 and 7 are in same component or nor
    cout << "Checking before union:\n";
    if(ds.findParent(3) == ds.findParent(7))
        cout << "3 ad 7 have same parent\n";
    else
        cout << "3 and 7 do not have same parent\n";
    
    ds.unionByRank(3, 7);

    // Check again
    cout << "Checking after union:\n";
    if(ds.findParent(3) == ds.findParent(7))
        cout << "3 ad 7 have same parent\n";
    else
        cout << "3 and 7 do not have same parent\n";
    return 0;
}