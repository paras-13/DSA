// Longest Common Substring (DP)
#include <iostream>
#include <vector>
using namespace std;

// Recursive Implementation of the code --> But it is not optimised
// For optimization we will use memoization or tabular method
int recursive(string &s1, string &s2, int n1, int n2, int ct)
{
    if (n1 == 0 || n2 == 0)
        return ct;
    if (s1[n1 - 1] == s2[n2 - 1])
        ct = recursive(s1, s2, n1 - 1, n2 - 1, ct + 1);
    return max(ct, max(recursive(s1, s2, n1 - 1, n2, 0), recursive(s1, s2, n1, n2 - 1, 0)));
}

//? Using Memoization

int memo(string &s1, string &s2, int i, int j, vector<vector<int>> &dp, int &maxLen) {
    if(i<0 || j<0)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(s1[i] == s2[j]) {
        dp[i][j] = 1+memo(s1, s2, i-1, j-1, dp, maxLen);
        maxLen = max(maxLen, dp[i][j]);
    }
    else
        dp[i][j] = 0;

    return dp[i][j];

}
int memoization(string &s1, string &s2, int n1, int n2)
{
    vector<vector<int>>dp(n1, vector<int>(n2, -1));
    int maxLen = 0;
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++)
            memo(s1, s2, i, j, dp, maxLen);
    }
    return maxLen;
}

//? Using Tabulation
int tabulation(string s1, string s2, int n1, int n2) {
    vector<vector<int>>dp(n1+1, vector<int>(n2+1));
    int ans = 0;
    for(int i=0; i<=n1; i++)
        dp[i][0] = 0;
    for(int j=0; j<=n2; j++)
        dp[0][j] = 0;
    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}
int main()
{
    string str1, str2;
    cout << "Enter string1: ";
    cin >> str1;
    cout << "Enter string2: ";
    cin >> str2;
    int n1 = str1.length();
    int n2 = str2.length();

    // Naive Recursive approach
    cout << "rec: " << recursive(str1, str2, n1, n2, 0) << endl;

    // Using memoization
    cout << "Memo: " << memoization(str1, str2, n1, n2) << endl;
    
    // Using Tabulation
    cout << "tab: " << tabulation(str1, str2, n1, n2);
}
