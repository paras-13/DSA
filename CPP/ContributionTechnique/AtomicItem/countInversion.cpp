// Problem is to find number inversion in every subarray of an array
// Inversion is defined as arr[i] > arr[j] && i < j
// Using contribution technique we can solve this problem in O(n^2) time
// More optimised approach is using segement trees which takes time O(nlogn)
#include <iostream>
#include <vector>
using namespace std;
int findCountOfInversion(vector<int> &arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                cnt += (i + 1) * (n - j);
        }
    }
    return cnt;
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
    int res = findCountOfInversion(arr, n);
    cout << "Count of inversion in every subarray: " << res << endl;
}