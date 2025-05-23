// Longest Palindromic Subsequence
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string &s, string &t, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}
int lps(string &s)
{
    string t = s;
    reverse(s.begin(), s.end());
    return lcs(s, t, s.length());
}
int main()
{
    string s;
    cout << "Enter strinng: ";
    cin >> s;

    // To calculate longest palindromic subsequence
    // optimise way is to calculate lcs of reversed and non-reversed part of this string
    // and this will lend us with max length of palindromic subsequence

    cout << lps(s);
    return 0;
}