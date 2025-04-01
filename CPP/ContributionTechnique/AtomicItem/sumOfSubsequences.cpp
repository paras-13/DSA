// Second atomic Contribution technique os to calculate sum of all subsequence of an array
// Time complexity: is O(n) and space is constant
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int sumOfSubsequence(vector<int> &arr, int n)
{
    int sum = 0;
    // 2^(n-1) is the number of subsequence that can be formed using n elements
    int cnt = pow(2, n - 1); // or (1 << (n-1)) can also be used
    for (int i = 0; i < n; i++)
    {
        sum += cnt * arr[i];
    }
    return sum;
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = sumOfSubsequence(arr, n);
    cout << "Sum of all subsequence: " << res << endl;
    return 0;
}