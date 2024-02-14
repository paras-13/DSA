//  Count number of digits using recursion
// Code -->
#include <iostream>
using namespace std;
int countDigits(int n)
{
    if(n==0) return 0;
    int count = countDigits(n/10);
    return count + 1;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << countDigits(num);
}