// Brian Kerninghan Algorithm for couting Set Bits in a binary number
// efficient method to count the number of set bits (1s) in the binary representation of an integer
// Time :- O(number of set bits)
// Efficient algorithm for set bit counting
#include <iostream>
using namespace std;
int setBits(int n) {
    int count = 0;
    while(n) {
        n = n&(n-1);
        count++;
    }
    return count;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Set bits: " << setBits(n);
    return 0;
}