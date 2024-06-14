// Calculating power in logN time Iteratively
// Using logic of Binary Exponentiation

//? Time Complexity : O(logN)
#include <iostream>
#include <string>
using namespace std;

int power(int x, int n) {
    int res = 1;
    while(n & 1) {
        if(n%2 != 0) 
            res  = res * x;
        x = x * x;
        n = n >> 1;
    }
    return res;
}
int main() {
    int num, pow;
    cout << "Enter number: ";
    cin >> num;
    cout << "Enter power: ";
    cin >> pow;
    cout << power(num, pow) << endl;
}