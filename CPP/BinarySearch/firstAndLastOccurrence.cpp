// First and Last Occurence of an Element in an array...
// Using Binary search
#include <iostream>
#include <vector>
using namespace std;
vector<int> firstAndLastOccurrence(vector<int> &arr, int n, int target) {
    int first = -1;
    int last = -1;
    int beg=0, end = n-1;
    while(beg <= end) {
        int mid = beg + (end-beg)/2;
        if(arr[mid] == target) {
            first = mid;
            end = mid-1;
        }
        else if(arr[mid] > target)
            end = mid-1;
        else
            beg = mid+1;
    }

    beg=0, end=n-1;
    while(beg <= end) {
        int mid = beg + (end-beg)/2;
        if(arr[mid] == target) {
            last = mid;
            beg = mid+1;
        }
        else if(arr[mid] > target) 
            end = mid-1;
        else
            beg = mid+1;
    }
    return {first, last};
}
int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements in sorted form - Repetition allowed: ";
    for(int i=0; i<n; i++) 
        cin >> arr[i];
    cout << "Enter target value: ";
    cin >> target;
    vector<int>res = firstAndLastOccurrence(arr, n, target);
    cout << res[0] << " " << res[1];
}