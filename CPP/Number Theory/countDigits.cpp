// Count digits of a number;
#include <iostream>
using namespace std;
int countDigits(int num) {
    if(num == 0) return 0;
    return countDigits(num/10) + 1;
}
int main() {
    int n;
    cout << "Enter num: ";
    cin >> n;
    int num = n;
    int count = 0;
    while(n!=0) {
        count++;
        n/=10;
    }
    cout << count << endl;
    // Recursively
    cout << "Using recursion: " << countDigits(num) << endl;
}
