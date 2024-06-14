// All Divisiors of a Number N in increasing order....
// Time Complexity:
//? Naive Approach: O(n);
//? Efficient Approach: O(sqrt(n));
#include <iostream>
#include <cmath>
using namespace std;

void printDivisorsNaive(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }
}

void printDivisors(int n, int i)
{
    for(int i=1; i*i <n; i++) {
        if(n%i == 0) cout << i << " ";
    }
    for(int i=sqrt(n); i>=1; i--) {
        if(n%i == 0) cout << n/i << " ";
    }
}
int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    //! Naive Solution
    cout << "Naive Approach: ";
    printDivisorsNaive(num);

    //! Efficient Solution
    cout << "\nEfficient Approach: ";
    printDivisors(num, 1);
}