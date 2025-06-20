// find min vaue in rotated sorted array
#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int> &arr, int mid, int n) {
    if(arr[mid] <= arr[n-1])
        return true;
    return false;
}
int solve(vector<int> &arr, int n) {
    int beg = 0, end = n-1;
    int res = -1;
    while(beg <= end) {
        int mid = beg + (end - beg)/2;
        if(check(arr, mid, n)) {
            res = mid;
            end = mid-1;
        }
        else
            beg = mid+1;
    }
    return res == -1 ? -1 : arr[res];
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    int res = solve(v, n);
    if(res == -1)
        cout << "Not found";
    else
        cout << "Min Element in rotated sorted array: " << res;
}