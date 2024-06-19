// Sum of Array using Recursion
#include <iostream>
using namespace std;
int sumOfArray(int arr[], int n) {
    if(n==1) return arr[0];
    int sum = sumOfArray(arr+1, n-1);
    return sum += arr[0];
}

// Another approach
int sumOfArray2(int arr[], int n, int i) {
    if(i == n) return 0;
    return arr[i] + sumOfArray2(arr, n, ++i);
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++) 
        cin >> arr[i];
    cout << "Sum of array elements method 1: " << sumOfArray(arr, n) << endl;
    cout << "Sum of Array elements method 2: " << sumOfArray2(arr, n, 0) << endl;
}