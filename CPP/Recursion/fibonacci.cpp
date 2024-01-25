// Sum of Fibonacci series using Recursion
#include <iostream>
using namespace std;
int fibonacci(int val)
{
    if (val == 0)
        return 0;

    if(val == 1) 
        return 1;
    return fibonacci(val-1)+fibonacci(val-2);
}
int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << fibonacci(num);
}