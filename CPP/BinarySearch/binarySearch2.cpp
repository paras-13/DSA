// Now the array is sorted in descending order, so we have to find the target value in the array according to that;
#include <iostream>
#include <vector>
using namespace std;
int BinarySearch2(vector<int> &arr, int n, int target) {
    int beg = 0;
    int end = n-1;
    int mid;
    while(beg <= end) {
        mid = beg + (end-beg)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            beg = mid+1;
        else
            end = mid-1;
    }
    return -1;
}
int main() {
    int n, target;
    cout << "Entr size of n: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter element in sorted descending order: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Enter target: ";
    cin >> target;
    cout << BinarySearch2(arr, n, target); 
}