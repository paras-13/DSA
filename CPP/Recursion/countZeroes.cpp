// To count number of zeroes in a number using recursion
#include <iostream>
using namespace std;
// Using reference variable
void countZeroes(int n, int &count) {
    if(n==0) return;
    int x = n%10;
    if(x == 0) count++;
    countZeroes(n/10, count);
}

// Using return type
int countZeroes(int n) {
    if(n == 0) return 0;
    int smallAns = countZeroes(n/10);
    int lastDigit = n%10;
    if(lastDigit == 0)
        return smallAns + 1;
    else return smallAns;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int count=0;
    countZeroes(n, count);  // Reference Case
    cout << "Number of zeroes present(reference): " << count << endl;

    // Return case;
    cout << "Number of zeroes present(return): " <<  countZeroes(n);
}