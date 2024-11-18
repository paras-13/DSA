// Count of an element in sorted array using Binary Search
// Time Complexity: O(logN)
#include <iostream>
#include <vector>
using namespace std;

int countElement(vector<int> &arr, int n, int target) {
    int first=0, last=0;
    int beg=0, end=n-1;
    while(beg <= end) {
        int mid = beg + (end-beg)/2;
        if(arr[mid] == target) {
            first = mid;
            end = mid-1;
        }
        else if(arr[mid] > target)
            end = mid-1;
        else 
            beg = mid+1;
    }
    beg=0; end=n-1;
    while(beg <= end) {
        int mid = beg + (end-beg)/2;
        if(arr[mid] == target) {
            last = mid;
            beg = mid+1;
        }
        else if(arr[mid] > target)
            end = mid-1;
        else
            beg = mid+1;
    }
    return last-first+1;
}
int main() {
    int n, target;
    cout << "Enter size o af array: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements in Sorted order: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Enter target element to count: ";
    cin >> target;
    cout << countElement(arr, n, target);
}