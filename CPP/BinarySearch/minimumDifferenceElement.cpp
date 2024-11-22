// Problem Statement:- Find Minimum difference Element in a Sorted Array: 
// Using Binary Search
#include <iostream>
#include <vector>
using namespace std;
int findMinDifference(vector<int> &arr, int n, int target) {
    
    // So here in this problem our aim at first will be to find target:
    // if target is found than return 0;
    // if not found -> then
    // return minimum difference between (target-prev, target-next) that is basically the floor and ceil of that target
    // Hence, if target is not present in the array, find floor and ceil and return difference which is minimum

    int beg = 0;
    int end = n-1;
    while(beg <= end) {
        int mid = beg + (end-beg)/2;
        if(arr[mid] == target)
            return 0;
        else if(arr[mid] > target)
            end = mid-1;
        else
            beg = mid+1;
    }
    if(end <0 || beg>=n)
        return -1;
    
    int prev = abs(target-arr[end]);
    int next = abs(target-arr[beg]);
    return min(prev, next);
}
int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Enter target element: ";
    cin >> target;
    int res = findMinDifference(arr, n, target);
    if(res == -1)
        cout << "Not Possible";
    else
        cout << res << endl;
}