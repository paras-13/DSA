// Sum of digits using recursion
// Code -->
#include <iostream>
using namespace std;
int sumOfDigits(int n)
{
    if(n==0) return 0;
    int lastDig = n%10;
    return lastDig + sumOfDigits(n/10);
}
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << sumOfDigits(num);
}