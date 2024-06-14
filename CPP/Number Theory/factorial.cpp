// Factorial of a Number;
#include <iostream>
using namespace std;
int factorial(int n) {
    if(n == 0) return 1;
    return n * factorial(n-1);
}
int main() {
    int n;
    cin >> n;
    int fact = 1;
    for(int i=1; i<=n; i++) 
        fact *= i;
    cout << fact << endl;
    // Recursively
    cout << "Using recursion:- " << factorial(n) << endl;
}