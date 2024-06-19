// To return first Index of a Number in Array using Recursion:
#include <iostream>
using namespace std;

int findFirstIndex(int arr[], int n, int ele, int i) {
    if(i == n) return -1;
    if(arr[i] == ele) return i;
    return findFirstIndex(arr, n, ele, ++i);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++) 
        cin >> arr[i];
    int ele;
    cout << "Enter element to find first index for: ";
    cin >> ele;
    int firstIndex = findFirstIndex(arr, n, ele, 0);
    if(firstIndex != -1) cout << "First Index is: " << firstIndex << endl;
    else cout << "Element not found" << endl;
}