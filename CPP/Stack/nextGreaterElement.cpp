// Finding next greater element in an array:
// First greater element that is to the right of x in the same array.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> printNextGreater(vector<int> arr, int n) {
    vector<int>res(n);
    stack<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--) {
        while(st.top()!=-1 && st.top() < arr[i])
            st.pop();
        res[i] = st.top();
        st.push(arr[i]);
    }
    return res;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int>v(n);
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
        cin >> v[i];
    vector<int>res = printNextGreater(v, n);
    for(int i=0; i<n; i++)
        cout << res[i] << " ";
}