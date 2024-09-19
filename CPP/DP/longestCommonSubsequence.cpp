// Longest Common Subsequence (LCS)
// Optimization using DP
#include <iostream>
#include <vector>
using namespace std;

// Naive Recursive Solution
// Time Complexity: O(2^n)
int recursive(string &s1, string &s2, int n, int m) {
    if(n == 0 || m == 0)
        return 0;
    if(s1[n-1] == s2[m-1])
        return 1 + recursive(s1, s2, n-1, m-1);
    else
        return max(recursive(s1, s2, n-1, m), recursive(s1, s2, n, m-1));
}

// Using Memoization (DP)
// Time Complexity: (n*m)
int memo(string &s1, string &s2, int n, int m, vector<vector<int>> &dp) {
    if(dp[n][m] != -1)
        return dp[n][m];
    if(n == 0 || m == 0)
        return dp[n][m] = 0;
    else {
        if(s1[n-1] == s2[m-1])
            dp[n][m] = 1 + memo(s1, s2, m-1, n-1, dp);
        else {
            dp[n][m] = max(memo(s1, s2, n-1, m, dp), memo(s1, s2, n, m-1, dp));
        }
    }
    return dp[n][m];
}

// Using Tabulation
// Time Complexity: O(n*m);
int tabulation(string s1, string s2, int n, int m) {

}
int lcs(string s1, string s2, int n, int m) {
    // Recursive Approach
    cout << "Using recursive Approach: " << recursive(s1, s2, n, m) << endl;

    // Memoization
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
    cout << "using Memoization: "<< memo(s1, s2, n, m, dp) << endl;

    // Tabulation
    return tabulation(s1, s2, n, m);
}
int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    int n = s1.length();
    int m = s2.length();
    int len = lcs(s1, s2, n, m);
    if(len > 0)
        cout << "Subsequence length: " << len <<endl;
    else
        cout << "Subsequence not found" << endl;

}