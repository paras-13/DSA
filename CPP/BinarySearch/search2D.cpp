// Search In a 2D matrix
// Solved using two approaches:
/*
    1- O(n*log(m))
    2- O(log(n*m))
*/
#include <iostream>
#include <vector>
using namespace std;

// TIme Complexity: O(n*log(m))
bool search2D(vector<vector<int>> &arr, int target)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < n; i++)
    {
        int beg = 0;
        int end = m - 1;
        int mid;
        while (beg <= end)
        {
            mid = (beg + end) / 2;
            if (arr[i][mid] == target)
                return true;
            else if (target < arr[i][mid])
                end = mid - 1;
            else
                beg = mid + 1;
        }
    }
    return false;
}
// Time Complexity: O(log(n*m))
bool search2D(vector<vector<int>> &arr, int n, int m, int target)
{
    int beg = 0;
    int end = n * m - 1;
    while (beg <= end)
    {
        int mid = (beg + end) / 2;
        int row = mid / m;
        int col = mid % m;
        if (arr[row][col] == target)
            return true;
        else if (arr[row][col] > target)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return false;
}

int main()
{
    int n1, n2, target;
    cout << "Enter number of rows: ";
    cin >> n1;
    cout << "Enter number of columns: ";
    cin >> n2;
    vector<vector<int>> arr(n1, vector<int>(n2));
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    cout << "Enter target to find: ";
    cin >> target;
    bool ispresent = search2D(arr, target);
    bool isPresent = search2D(arr, n1, n2, target);
    if (isPresent && ispresent)
        cout << "Target is present" << endl;
    else
        cout << "Target is not present" << endl;
}
