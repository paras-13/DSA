// Number is Prime or not;

// Time Complexity
//? Naive Approach : O(n)
//? Efficient Approach : O(sqrt(n))

#include <iostream>
#include <cmath>
using namespace std;

// Naive Approach
bool checkPrimeNaive(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Efficient Approach
bool checkPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

// A more Efficient approach is two filter out with some case (3 times faster than efficient approach):
bool mostEfficient(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i <= sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int 
int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    //! Naive Approach
    cout << "Using naive Approch " << checkPrimeNaive(num) << endl;

    //! Efficient Approach
    cout << "Efficient Approach " << checkPrime(num) << endl;

    //! Most Efficient
    cout << "Most Efficient " << mostEfficient(num) << endl;
}