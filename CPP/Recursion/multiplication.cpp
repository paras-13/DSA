// Multiplication using recursion without using * operator
#include <iostream>
using namespace std;

int product(int n, int m)
{
    if(m == 0) return 0;
    return n+product(n, m-1);
}
int main()
{
    int n, m;
    cout << "Enter first num: ";
    cin >> n;
    cout << "Enter second num: ";
    cin >> m;
    cout << "Product of both number is: " << product(n, m);;
}