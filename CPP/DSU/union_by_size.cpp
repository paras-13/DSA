/*
    Time Complexity Analysis:

    - The findParent function uses path compression, and unionBySize uses union by size.
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

// Union By Size
#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    private:
        vector<int> parent, size;
    public:
    DisjointSet(int n) {
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if(parentU == parentV)
            return;
        if(size[parentU] < size[parentV]) {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // Check for whether 3 and 7 are in same component or nor
    cout << "Checking before union:\n";
    if(ds.findParent(3) == ds.findParent(7))
        cout << "3 ad 7 have same parent\n";
    else
        cout << "3 and 7 do not have same parent\n";
    
    ds.unionBySize(3, 7);

    // Check again
    cout << "Checking after union:\n";
    if(ds.findParent(3) == ds.findParent(7))
        cout << "3 ad 7 have same parent\n";
    else
        cout << "3 and 7 do not have same parent\n";
    return 0;
}