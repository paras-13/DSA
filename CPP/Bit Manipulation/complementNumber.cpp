// To Complement a number using bitwise operators
#include <iostream>
#include <cmath>
using namespace std;
int computeComplement(int num) {
    int len = (int)log2(num) + 1;  // To find the length of binary representation of number n (log(n)base2 + 1 formula is used);

    // To create a mask og this length, left shift operator is used;
    int mask = (long)(1 << len) - 1;

    return num ^ mask;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Complement of " << n << " is: " << computeComplement(n);
    return 0;
}