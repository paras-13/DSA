// Problem

// The problem states that we have to find the total amount number which can be formed upto digit n should be unique
// constraints : 0 <= n <= 8



/*
// Brute Force approach 
this problem can be done using a brute force approach where we can loop over all numbers lying in the range of digits, and then check for uniquness of every number
   
// using backtracking
a slight optimization of brute force is using backtracing and generating only unique numbers
*/

// Now the most optimised approach is by using math + dp
// this problem can be seen as a prmutaion problem, where we need to calculate the number of ways to create unique numbers using 0-9 number in n digits

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int findUnique(int n) {
    if(n == 0)
        return 1;
    vector<int> dp(20, 0);
    dp[0] = 1;
    dp[1] = 9;
    for(int i=2; i<=n; i++) 
        dp[i] = (10-i+1) * dp[i-1];
    int res = accumulate(dp.begin(), dp.end(), 0);
    return res;
}
int main() {
    int n;
    cin >> n;
    cout << findUnique(n);
    return 0;
}