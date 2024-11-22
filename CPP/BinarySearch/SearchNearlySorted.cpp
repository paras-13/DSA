// Searching in a Nearly Sorted Array
// Problem Statement:
/*
    Given a sorted array arr of size n, some elements of array are moved to either of the adjacent positions, i.e; arr[i]
    may be present at arr[i+1] or arr[i-1], i.e; arr[i] can only be swapped with either arr[i+1] or arr[i-1]. 
    The task is to search for an element in this array.
*/

// Follow Up: Required Time complexity to solve:- O(logN);

#include <iostream>
#include <vector>
using namespace std;

int searchInNearlySorted(vector<int> &arr, int n, int target) {
    // Using binary Search
    int beg = 0;
    int end = n-1;
    int mid;
    while(beg <= end) {
        int mid = beg + (end-beg)/2;
        
        // For handling the segmentation error in accessing prev and next element
        int prev = (mid-1+n)%n;  
        int next = (mid+1)%n;
        
        if(arr[mid] == target)
            return mid;
        if(arr[next] == target)
            return next;
        if(arr[prev] == target)
            return prev;
        if(arr[mid] > target)
            end = mid-2;
        else
            beg = mid+2;
    }
    return -1;
}
int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int>v(n);
    cout << "Enter elements in nearly sorted manner: ";
    for(int i=0; i<n; i++)
        cin >> v[i];
    cout << "Enter target: ";
    cin >> target;
    cout << searchInNearlySorted(v, n, target);
}