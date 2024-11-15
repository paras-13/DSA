#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

pair<string, int> LRS(string s, int n, vector<vector<int>> &dp) {
    pair<string,int> Lrs;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i != j && s[i-1] == s[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = n, j = n;
    string lrs;
    while(i > 0 && j > 0) {
        if(dp[i][j] == dp[i-1][j-1] + 1) {
            lrs.push_back(s[i-1]);
            i--;
            j--;
        }
        else if(dp[i][j] == dp[i-1][j]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lrs.begin(), lrs.end());
    Lrs = make_pair(lrs, dp[n][n]);
    return Lrs;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    pair<string, int> lrs = LRS(s, n, dp);
    cout << "LRS: " << lrs.first << "\nLength of LRS: " << lrs.second << endl;

    return 0;
}
