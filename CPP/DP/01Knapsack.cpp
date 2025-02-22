// 01 Knapsack Problem
// Code -->
#include <iostream>
#include <vector>
using namespace std;

// Recursive approach
int recursive(vector<int> &weight, vector<int> &value, int n, int W)
{
    if (W == 0 || n == 0)
        return 0;

    // ? if the weight of current item is more then the knapsack weight limit, then we will leave this item and move ahead
    if (weight[n - 1] > W)
        return recursive(weight, value, n - 1, W);

    //? I the situation where the item weight is less than the knapsack limit
    //? We have two choice
    /*
    ? either choose current element
    ? move to next element
    */
    int choose = value[n - 1] + recursive(weight, value, n - 1, W - weight[n - 1]);
    int leave = recursive(weight, value, n - 1, W);
    return max(choose, leave);
}

int memoized(vector<int> &weight, vector<int> &value, int n, int w, vector<vector<int>> &dp)
{
    if (w == 0 || n == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (weight[n - 1] > w)
        dp[n][w] = memoized(weight, value, n - 1, w, dp);
    else
    {
        int choose = value[n - 1] + memoized(weight, value, n - 1, w - weight[n - 1], dp);
        int leave = memoized(weight, value, n - 1, w, dp);
        dp[n][w] = max(choose, leave);
    }
    return dp[n][w];
}
int main()
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> weight(n);
    vector<int> value(n);
    cout << "Enter weight of items: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "Enter value of items: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    // Recursive approach
    // TC: O(2^n)
    cout << "Recursive approach: ";
    cout << recursive(weight, value, n, W);

    // Memoized approach
    // TC: O(n*W)
    // SC: O(n*W)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    cout << "\nMemoized approach: ";
    cout << memoized(weight, value, n, W, dp);
    cout << "\nTabulation approach: ";
    // Tabulation approach
    // On pattern which is observable from the recursive approach is that
    // dp[i][j] value is dependent on max(dp[i-1][j], dp[i-1][j-weight[i-1]]+value[i-1])
    // TC: O(n*W)
    // SC: O(n*W)
    vector<vector<int>> dpTable(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weight[i - 1] > w)
                dpTable[i][w] = dpTable[i - 1][w];
            else
            {
                int choose = value[i - 1] + dpTable[i - 1][w - weight[i - 1]];
                int leave = dpTable[i - 1][w];
                dpTable[i][w] = max(choose, leave);
            }
        }
    }
    cout << dpTable[n][W];
    return 0;
}