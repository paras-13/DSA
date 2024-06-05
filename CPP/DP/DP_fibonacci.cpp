#include <iostream>
#include <vector>
using namespace std;

// Normal Recursive
int fib1(int n) {
    if(n <=1) return n;
    int ans = fib1(n-1) + fib1(n-2);
    return ans;
}

// DP Memoization
int fib2(int n, vector <int> &dp) {
    
    // base case
    if(n<=1) return n;
    
    //intermediate case
    if(dp[n] != -1) return dp[n];
    
    // final case
    dp[n] =  fib2(n-1, dp) + fib2(n-2, dp);
    return dp[n];
}

// DP Tabulation
int fib3(int n, vector<int> &dp) {
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Space Optimization
int fib4(int n) {
    int first = 0;
    int second = 1;
    int third;
    for(int i=2; i<=n; i++) {
        third = first+second;
        first = second;
        second = third;
    }
    return third;
}
int main() {
    int n;
    cin >> n;
    vector <int> dp(n+1);
    for(int i=0; i<=n; i++) dp[i] = -1;

    // Recursive
    cout << fib1(n) << endl;  

    // Top - Down  :- O(N + N), O(N)
    cout << fib2(n, dp) << endl;

    // Bottom - Up    O(N), O(N)
    cout << fib3(n, dp) << endl;

    // Space Optimized      O(N),   O(1);
    cout << fib4(n) << endl;
}
