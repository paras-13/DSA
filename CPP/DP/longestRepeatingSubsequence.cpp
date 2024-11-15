// Longest Repeating Subsequence
// To find a subsequence in given string s, which should be repeating and longest
// Main thing is that the two or more same subsequene should not hold similar index values
#include <iostream>
#include <vector>
using namespace std;
int LRS(string s, int n, vector<vector<int>> &dp) {
    string s1 = s;
    string s2 = s;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i != j && s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    } 
    return dp[n][n];
}
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int n = s.length();
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    cout << "Length of Longest Repeating Subsequence " << LRS(s, n, dp);
    return 0;
}