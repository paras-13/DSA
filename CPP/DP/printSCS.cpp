// Printing SCS (Shortest Common Supersequence)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string printSCS(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else    
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i=n, j=m;
    string scs;
    while(i>0 && j>0) {
        if(s1[i-1] == s2[j-1]) {
            scs.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i][j-1] > dp[i-1][j]) {
            scs.push_back(s2[j-1]);
            j--;
        }
        else {
            scs.push_back(s1[i-1]);
            i--;
        }
    }
    while(i>0) {
        scs.push_back(s1[i-1]);
        i--;
    }
    while(j>0) {
        scs.push_back(s2[j-1]);
        j--;
    }
    reverse(scs.begin(), scs.end());
    return scs;
}
int main() {
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;
    cout << "Shortest Common Supersequence of strings is: " << printSCS(s1, s2);
}