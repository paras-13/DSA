// Count Set bits in binary representation of a number
// Time:- LogN, Space- O(1);
#include <iostream>
using namespace std;
int setBits(int n) {
    int count = 0;
    while(n) {
        if(n&1) count++;
        n >>= 1;
    }
    return count;
}
int main() {
    int n;
    cout << "Enter a num: ";
    cin >> n;
    cout << "Number of set bits are: " << setBits(n) << endl;
    return 0;
}