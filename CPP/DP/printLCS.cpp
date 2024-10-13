#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string printLcs(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = m, j = n;
    string LCS = "";
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            LCS.push_back(s1[i - 1]);
            i--;
            j--;
        } else {
            if (dp[i - 1][j] >= dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(LCS.begin(), LCS.end());
    return LCS;
}

int main() {
    string s1, s2;
    cout << "Enter string1: ";
    cin >> s1;
    cout << "Enter string2: ";
    cin >> s2;
    string lcs = printLcs(s1, s2);
    if(lcs.empty())
        cout << "LCS not found" << endl;
    else
        cout << "Longest Common Subsequence is: " << lcs << endl;

}
