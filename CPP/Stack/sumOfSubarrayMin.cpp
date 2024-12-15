// Sum of subarray minimum using stack
// Medium-Hard Problem
// Given an array of integers, find the sum of the minimum elements of all subarrays of the array.
// Example:
// Input: [3, 1, 2, 4]
// Output: 17
/*
    min(3 1 2 4) = 1
    min(3 1 2) = 1
    min(3 1) = 1
    min(3) = 3
    min(1 2 4) = 1
    min(1 2) = 1
    min(2 4) = 2
    min(2) = 2
    min(4) = 4
    Sum = 1 + 1 + 1 + 3 + 1 + 1 + 2 + 2 + 4 = 17 
*/
// Can be done easily using brute force approach but it will take O(n^2) time complexity.
// To solve efficiently in O(n) time complexity, we can use stack.

// Stack approach
// Approach is to find the next smaller element(NSE) position and previous smaller element position(PSE)
// After finding the appropriate position we have to apply a formula
// This formula is simulation based, means based on observation
// let say left gives us the posotion of previous smaller element
// and right gives us the value of next right element
//! then using (left+1) * (right+1) we can get the total number of subarrays in which the current element is minimum
// and then we multiply this freq with the number
// and simultaneously we add this to the answer

// for bigger text case, sum can exceed integer limits, so eiter use long long or mod with 10^9+7

// Code
#include <iostream>
#include <vector>
#include <stack>
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void findNSE(vector<int> &arr, int n, vector<int> &nse, stack<pair<int, int>> &st) {
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && st.top().first >= arr[i])
            st.pop();
        if(st.empty())
            nse[i] = n;
        else
            nse[i] = st.top().second;
        st.push({arr[i], i});
    }
}
void findPSE(vector<int> &arr, int n, vector<int> &pse, stack<pair<int, int>> &st) {
    for(int i=0; i<n; i++) {
        while(!st.empty() && st.top().first > arr[i])
            st.pop();
        if(st.empty())
            pse[i] = -1;
        else
            pse[i] = st.top().second;
        st.push({arr[i], i});
    }
}
int subarrayMinimum(vector<int> &arr, int n) {
    vector<int>nse(n);
    vector<int>pse(n);
    // First we find Next smaller element;
    stack<pair<int, int>>st;
    findNSE(arr, n, nse, st);
    st = stack<pair<int, int>> ();
    findPSE(arr, n, pse, st);
    int sum = 0;
    for(int i=0; i<n; i++) {
        int left, right;

        // Handling edge cases
        if(pse[i] == -1)
            left = i;
        else
            left = i-pse[i]-1;
        
        if(nse[i] == n)
            right = n-i-1;
        else
            right = nse[i]-i-1;
        
        // Important formula
        int freq = (left+1) * (right+1);
        sum = (sum + (1LL*freq*arr[i])%mod)%mod;
    }
    return sum;
}
int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int>v(n);
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
        cin >> v[i];

    cout << "Sum of subarray minimum: " << subarrayMinimum(v, n) << endl;
}