// Count Distinct Number of element in array;
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// Naive Approach:
// Time Complexity O(n^2)
int countDistinct(int arr[], int n) {
    int count=1;
    for(int i=1; i<n; i++) {
        int j=0;
        for(j=0; j<i; j++) {
            if(arr[i] == arr[j]) {
                break;
            }
        }
        if(i == j) count++;
    }
    return count;
}

// NLogN approach
int countDistinct2(int arr[], int n) {
    int count = 1;
    sort(arr, arr+n);
    for(int i=0; i<n-1; i++) {
        if(arr[i]!=arr[i+1])
            count++;
    }
    return count;
}

// O(n) approach
// Using set
int countDistinct3(int arr[], int n) {
    set<int>s;
    for(int i=0; i<n; i++) 
        s.insert(arr[i]);
    return s.size();
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) 
        cin >> arr[i];
    cout << "O(n^2) approach: " << countDistinct(arr, n) << endl;
    cout << "O(NLogN) using Sorting: " << countDistinct2(arr, n) << endl;
    cout << "O(N) using Set" << countDistinct3(arr, n);
}