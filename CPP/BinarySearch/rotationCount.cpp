// Count number of times a sorted array is rotated
#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> &arr, int n) {
     int beg = 0, end=n-1;
    if(arr[end] >= arr[beg])
        return 0;
    while(beg <= end) {
        int mid = beg + (end-beg)/2;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            return mid;
        if(arr[0] <= arr[mid])
            beg = mid+1;
        else
            end = mid-1;
    }
    return 0;
}
int rotationCount(vector<int> &arr, int n) {
    // Finding minimum element in the rotated sorted array:
    int minPos = findMin(arr, n);
    cout << minPos << endl;
    return (n-minPos)%n; 
   
}
int main() {
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements in rotated sorted form: ";
    for(int i=0; i<n; i++) 
        cin >> arr[i];
    cout << "Number of times array is rotated: " << rotationCount(arr, n) << endl;
    
}