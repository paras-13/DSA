// In order Agnostic Binary Search we are not given that in which order (Ascending or Descending) the array is sorted...
// Hence we first find this, then we will apply binary search
#include <iostream>
#include <vector>
using namespace std;
int OrderAgnosticBS(vector<int>arr, int n, int target) {
    int beg = 0;
    int end = n-1;
    bool isAsc;
    if(arr[beg] <= arr[end])
        isAsc = true;
    else
        isAsc = false;
    while(beg <= end) {
        int mid = beg + (end-beg)/2;
        if(arr[mid] == target)
            return mid;

        if(isAsc) {                     // If in ascending order
            if(arr[mid] > target)
                end = mid-1;
            else
                beg = mid+1;
        }

        else {                          // If in descending order
            if(arr[mid] > target)
                beg = mid+1;
            else
                end = mid-1;
        }
    }
    return -1;
}

int main() {
    int n, target;
    cout << "Enter array size: ";
    cin >> n;
    vector<int>v(n);
    cout << "Enter array elements in sorted order: ";
    for(int i=0; i<n; i++)
        cin >> v[i];
    cout << "Enter target value: ";
    cin >> target;
    cout << OrderAgnosticBS(v, n, target);
    return 0;
}