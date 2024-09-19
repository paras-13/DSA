// To Check a number is power of 2 or not
// Two approaches for this problem
// One is to count the number of set bits and if the number of set bits is greater than 1 than return false
// Other is to bitwise and n with n-1, if res is not 0 return false;
#include <iostream>
using namespace std;

// Efficient O(1) approach
bool bitMask(int n) {
    if(n <= 0)
        return false;
    if(n&(n-1))
        return false;
    return true;
}

// Using Brian Algo for Counting Set Bits
// Time Complexity: O(Number of Set Bits)
bool brianAlgo(int n) {
    int count = 0;
    if(n <= 0)
        return false;
    while(n) {
        n = n&(n-1);
        count++;
        if(count > 1)
            return false;
    }
    return true;
}

bool isPowerOfTwo(int n) {
    bool method1 = bitMask(n); // Efficient method 1 in O(1)
    bool method2 = brianAlgo(n);  // Second Approach
    return method1 && method2;
}
int main() {
    int n;
    cout <<  "Enter a number: ";
    cin >> n;
    bool powerOfTwo = isPowerOfTwo(n);
    if(powerOfTwo)
        cout << "Given number is power of Two" << endl;
    else
        cout << "Given number is not power of Two" << endl;
}