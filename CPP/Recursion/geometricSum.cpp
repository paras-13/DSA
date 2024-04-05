// Sum of geometric Series using Recursion
// Series is  --> 1/2^0, 1/2^1 , 1/2^2, 1/2^3, 1/2^4.....1/2^k
#include <iostream>
#include <cmath>
using namespace std;
double geometricSum(int k) {

    // base
    if(k == 0) 
        return 1;

    // recursive case
    double smallAns = geometricSum(k-1);

    // Calculation
    return smallAns + 1.0/pow(2,k);
}
int main() {
    int k;
    cin >> k;
    cout << geometricSum(k);
}