#include <iostream>
#include <vector>
using namespace std;

// DP Memoization
int fibo(int n, vector <int> &dp) {
    
    // base case
    if(n<=1) return n;
    
    //intermediate case
    if(dp[n] != -1) return dp[n];
    
    // final case
    dp[n] =  fibo(n-1, dp) + fibo(n-2, dp);
    return dp[n];
}

// DP Tabulation
int fib(int n, vector<int> &dp) {
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main() {
    int n;
    cin >> n;
    vector <int> dp(n+1);
    for(int i=0; i<=n; i++) dp[i] = -1;
    cout << fibo(n, dp) << endl;
    cout << fib(n, dp);
}
