// Convert Decimal To Binary using Bit
// LogN approach
#include <iostream>
#include <algorithm>
using namespace std;
string decToBin(int n) {
    string bin;
    while(n) {
        if(n&1)
            bin.push_back('1');
        else
            bin.push_back('0');
        n >>= 1;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}
int main() {
    int n;
    cout << "Enter decimal number: ";
    cin >> n;
    cout << "In Binary: " << decToBin(n);
}