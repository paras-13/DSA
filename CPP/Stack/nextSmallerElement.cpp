// To generate next smaller element towards right
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextSmallerElement(vector<int> arr, int n) {
    vector<int>res(n);
    stack<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--) {
        while(st.top()!=-1 && st.top() >= arr[i])
            st.pop();
        res[i] = st.top();
        st.push(arr[i]);
    }
    return res;
}
int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int>v(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
        cin >> v[i];
    vector<int> res = nextSmallerElement(v, n);
    for(int it : res)
        cout << it << " ";
}