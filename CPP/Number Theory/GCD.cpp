// Gretest Common Divisior
// Time Complexity:
//? Naive Approach: O(min(n1, n2))
//? Efficient approach: O(log(min(n1, n2)))
#include <iostream>
#include <algorithm>
using namespace std;
int gcd_(int n1, int n2) {
    int res = min(n1, n2);
    while(res > 0) {
        if(n1%res == 0 && n2%res == 0)
            break;
        res--;
    }
    return res;
}

// Efficient approach for GCD
int gcd(int n1, int n2) {
    if(n2 == 0) return n1;
    return gcd(n2, n1%n2);
}
int main() {
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout<< "Enter second number: ";
    cin >> num2;

    //! Naive Approach
    cout << "Using Naive Approach " << gcd_(num1, num2) << endl;
    
    //! Efficient approach
    // Using euclidean algorithm
    cout << "Using Euclidean algorithm " << gcd(num1, num2) << endl;
}