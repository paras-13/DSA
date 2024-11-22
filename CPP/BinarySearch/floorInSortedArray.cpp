// Finding floor of a target element in sorted array using Binary Search
// Time Complexity: O(logN);
#include <iostream>
#include <vector>
using namespace std;
int floor(vector<int> &arr, int n, int target) {
    int beg = 0;
    int end = n-1;
    while(beg <= end) {
        int mid = beg + (end-beg)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            end = mid-1;
        else
            beg = mid+1;
    }
    return end;
}
int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements in sorted order: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Enter target to find floor for: ";
    cin >> target;
    int ind = floor(arr, n, target);
    if(ind == -1)
        cout << "Not Possible";
    else
        cout << "FLoor of " << target << " is: " << arr[ind];
}