// Sum of all subset of elements in a set
// Problem link -- > https://www.geeksforgeeks.org/problems/subset-sums2234/0
#include <iostream>
#include <vector>
using namespace std;
void findSum(vector<int> &Set, vector<int> &v, int n, int sum, int ptr) {
    if(ptr == n) {
        v.push_back(sum);
        return;
    }
    v.push_back(sum);
    for(int j=ptr; j<n; j++) {
        sum += Set[j];
        findSum(Set, v, n, sum, j+1);
        sum -= Set[j];
    }
    return;
}
vector<int> subsetSums(vector<int>Set, int n) {
    vector<int>v;
    findSum(Set, v, n, 0, 0);
    return v;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int>Set(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
        cin >> Set[i];
    cout << "Sum of all subsets of set: " << endl;
    vector<int>res = subsetSums(Set, n);
    for(int i=0; i<res.size(); i++)
        cout << res[i] << " ";
}