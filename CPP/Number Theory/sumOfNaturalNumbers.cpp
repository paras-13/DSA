// Sum of Natural Numbers
// We know the formula for sum of n natural number is (n*(n+1))/2
// but using this causes overflow, even if the result is not beyond the integer limit. We can avoid overflow up to some extent by dividing first.
#include <iostream>
using namespace std;

/*
    *Here multiplying by 1LL help to
    *perform calculations in long long,
	*so that answer should not be overflowed
*/
int findSum(int n) {
    if(n%2 == 0) 
        return (n/2) * 1LL*(n+1);
    else
        return ((n+1)/2) * 1LL * n;
}
int main() {
    int n;
    cin >> n;
    cout << findSum(n);
    return 0;
}