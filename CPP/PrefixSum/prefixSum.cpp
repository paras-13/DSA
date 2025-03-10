// Prefix Sum pattern
/*
 *   A technique used in array processing where each element of an array stores the sum of all the preceding elements, including itself.
 *   This precomputation allows for efficient and quick retrieval of cumulative sums for various subarrays.
 */

// Lets solve an example problem
// Problem:- Given a static array A of size N, perform Q queries of the form ?LR, where each query seeks to find the sum of elements in the range L to R in the array.

// Time Complexity: O(n + q) = O(N); where n is the size of the array and q is the number of queries.
// Code
#include <iostream>
#include <vector>
using namespace std;
vector<int> computePrefixSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    return prefixSum;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> prefixSum = computePrefixSum(arr);

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    while (q--)
    {
        int l, r;
        cout << "Enter query in the form ?lr";
        cin >> l >> r;
        if (l == 0)
            cout << prefixSum[r] << endl;
        else
        {
            cout << prefixSum[r] - prefixSum[l - 1] << endl;
        }
    }
}