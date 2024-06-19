// To check array element is present or not in array using Recursion
#include <iostream>
using namespace std;

bool checkElement(int arr[], int n, int ele) {
    if(n == 0) return false;
    if(arr[0] == ele) return true;
    return checkElement(arr+1, n-1, ele);
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
    cout << "Enter element to find: ";
    cin >> ele;
    bool isPresent = checkElement(arr, n, ele);
    if(isPresent) cout << "Element is present" << endl;
    else cout << "Element is not present" << endl;

}