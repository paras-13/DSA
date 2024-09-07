// GFG link --> https://www.geeksforgeeks.org/problems/nth-natural-number/1
//* Medium
/*
    Given a positive integer n. 
    You have to find nth natural number after removing all the numbers containing the digit 9.
*/
#include <iostream>
#define nl "\n"
using namespace std;
int findNth(long long n) {
    long long ans = 0;
    long long p = 1;
    while(n>0) {
        ans += p * (n%9);
        n /= 9;
        p *= 10;
    }
    return ans;
}
int main() {
    long long n;
    cin >> n;
    cout << findNth(n) << nl;
}