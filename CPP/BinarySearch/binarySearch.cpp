// For given sorted array, search for a given target element in array, and return index of that
// Array is sorted in ascending order
#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int>v, int n, int target) {
    int beg = 0;
    int end = n-1;
    int mid;
    while(beg <= end) {
        mid = beg+(end-beg)/2;
        if(v[mid] == target)
            return mid;
        else if(v[mid] > target)
            end = mid-1;
        else
            beg = mid+1;
    }
    return -1;
}
int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int>v(n);
    cout << "Enter element in sorted order: ";
    for(int i=0; i<n; i++)
        cin >> v[i];
    cout << "Enter target value: ";
    cin >> target;
    cout << binarySearch(v, n, target);
}
