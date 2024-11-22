// Problem is to generate next Greater alphabetical element given as target, in the given sorted alphabetical letters aarray
// Using Binary Search in logN time
// If no such greater element is found than return the first element of letters array: 
#include <iostream>
#include <vector>
using namespace std;
char nextGreaterAlphabet(vector<char>arr, int n, int target) {
    int beg = 0;
    int end = n - 1;
    while(beg <= end) {
        int mid = beg + (end-beg)/2;
        if(arr[mid] > target)
            end = mid-1;
        else
            beg = mid+1;
    }
    if(beg >= n)
        return arr[0];
    return arr[beg];
}
int main() {
    int n;
    char target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<char>arr(n);
    cout << "Enter characters: ";
    for(int i=0; i<n; i++) 
        cin >> arr[i];
    cout << "Enter target: ";
    cin >> target;
    cout << "Next greater alphabet: " << nextGreaterAlphabet(arr, n, target);
}