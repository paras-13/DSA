// to count the number of bits needed to be flipped to convert A to B.
// Using Bit Manipulation
// Problem link --> https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
#include <iostream>
using namespace std;
int countBitsToFlip(int start, int goal) {
    int diff = start ^ goal;
    int ct = 0;
    while(diff) {   // Using Brian Algorithm to count set bit
        diff &= (diff-1);
        ct++;
    }
    return ct;
}
int main() {
    int org, tgt;
    cout << "Enter original number: ";
    cin >> org;
    cout << "Enter target number: ";
    cin >> tgt;
    cout << "Number of bits needed to be flipped: " << countBitsToFlip(org, tgt);
}