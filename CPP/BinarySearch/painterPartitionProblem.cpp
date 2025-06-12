// Painter Partition Problem
// link -> https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

// About Problem ==> In this problem we have to divide the total work among k workers
// each worker take 1 unit time to complete 1 unit work
// a single work cant be shared among multiple workers
// and we have to find minimum time taken by them to complete this work
// NOTE: painter has to paint in contiguous manner
/*
    eg case:- 1 2 3 4 5, k=2
    * 1 | 2 3 4 5  => max time = 14
    * 1 2 | 3 4 5  => max time = 12
    * 1 2 3 | 4 5  => max time = 9
    * 1 2 3 4 | 5  => max time = 10

    * Minimum time out of all these case is 9, hence answer is 9
*/

// code ->
// input -> n, k, array
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define ll long long
using namespace std;

bool isPossible(vector<ll> &arr, ll mid, int k)
{
    ll sum = 0;
    int cnt = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum + arr[i] <= mid)
            sum += arr[i];
        else
        {
            sum = arr[i];
            cnt++;
        }
    }
    if (cnt > k)
        return false;
    return true;
}

int solve(vector<ll> &arr, int n, int k)
{
    ll beg = *max_element(arr.begin(), arr.end());
    ll end = accumulate(arr.begin(), arr.end(), 0LL);
    ll res = 0;
    while (beg <= end)
    {
        ll mid = beg + (end - beg) / 2;
        if (isPossible(arr, mid, k))
        {
            res = mid;
            end = mid - 1;
        }
        else
            beg = mid + 1;
    }
    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve(arr, n, k);
}