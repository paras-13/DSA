// Shortest Common Supersequence
// Finding Length of Shortest Common Supersequence
#include <iostream>
#include <vector>
using namespace std;
int shortestCommonSupersequence(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return (n+m) - dp[n][m];
}
int main() {
    string str1, str2;
    cout << "Enter string 1: ";
    cin >> str1;
    cout << "Enter string 2: ";
    cin >> str2;
    cout << "Length of shortest common Supersequence is: " << shortestCommonSupersequence(str1, str2);
}