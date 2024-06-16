// To check whether an array is sorted or not using recursion
#include <iostream>
#include <vector>
using namespace std;
bool isSorted(int arr[], int n) {
    if(n == 0 || n == 1)
        return true;

    if(arr[0] > arr[1]) 
        return false;
    return isSorted(arr + 1, n-1);
    
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++) cin >> arr[i];
    if(isSorted(arr, n)) cout << "Array is Sorted" << endl;
    else cout << "Array is not Sorted" << endl;

}