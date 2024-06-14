// Count Number of Digits in Factorial Of a Number;
// floor(log N!) + 1

#include <iostream>
#include <cmath>
using namespace std;
int findDigits(int n) {
    if(n < 0) return 0;
    if(n <= 1) return 1;
    double digits = 0;
    for(int i=2; i<=n; i++) {
        digits += log10(i);
    }
    return floor(digits) + 1;

}
int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << findDigits(n) << endl;;
}