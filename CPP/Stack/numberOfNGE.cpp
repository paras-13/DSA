// Calculate total number of NGE to the right of each element in an array
// using stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> findNGE(vector<int> &arr, int n) {
    vector<int>res(n, -1);
    stack <int> st1, st2;
    for(int i=n-1; i>=0; i--) {
        while(!st2.empty() && st2.top() > arr[i]) {
            st1.push(st2.top());
            st2.pop();
        }
        while(!st1.empty() && st1.top() <= arr[i]) {
            st2.push(st1.top());
            st1.pop();
        }
        if(!st1.empty())
            res[i] = st1.size();
        st1.push(arr[i]);
    }
    return res;
}
int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int>v(n);
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
        cin >> v[i];
    vector<int>res = findNGE(v, n);
    cout << "Next Greater elements: ";
    for(int it : res)
        cout << it << " ";
}