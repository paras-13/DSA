// Factorial using Recursion
#include <iostream>
using namespace std;

int fact(int val)
{
    if(val<0) return -1;
    if(val==0)
        return 1;
    return val*fact(val-1);         // Recursion
}
int main()
{
    int num;
    cout << "Enter a number to find factorial!: ";
    cin >> num;
    cout << fact(num);
}