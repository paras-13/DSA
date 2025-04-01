// Sum of all subarray elements using contributution technique
#include <iostream>
#include <vector>
using namespace std;
int sumOfSubarray(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (i + 1) * (n - i) * arr[i];
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
    int sum = sumOfSubarray(arr, n);
    cout << "Sum of all subarray: " << sum << endl;
}
