// task is to check if there is a subset of the given set whose sum is equal to the given sum.
// Time Complexity is exponential 2^n in recursion;
// This problem can be optimised using DP
// Recursive code for this problem
#include <iostream>
using namespace std;
int isSubsetSum(int arr[], int n, int sum)
{
    if (n == 0)
        return (sum == 0) ? 1 : 0;
    return isSubsetSum(arr, n - 1, sum) + isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}
int main()
{
    int n;
    cout << "Enter size of set: ";
    cin >> n;
    int arr[n];
    cout << "Enter set elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cout << "Enter sum: ";
    cin >> sum;
    int result = isSubsetSum(arr, n, sum);
    if (result)
        cout << "Count of subset with given sum: " << result << endl;
    else
        cout << "No subset with given sum" << endl;
    return 0;
}