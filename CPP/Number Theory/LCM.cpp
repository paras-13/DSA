// LCm of two numbers
#include <iostream>
#include <algorithm>
// Time Complexity
//? Naive Approach : O(n1* n2 - max(n1-n2));
//? Efficient Approach : O(log(min(n1, n2)));

using namespace std;
int lcm_(int n1, int n2)
{
    int res = max(n1, n2);
    while (true)
    {
        if (res % n1 == 0 && res % n2 == 0)
            break;
        res++;
    }
    return res;
}

int gcd(int n1, int n2) {
    if(n2 == 0) return n1;
    return gcd(n2, n1%n2);
}
int lcm(int n1, int n2) {
    return (n1 * n2)/gcd(n1, n2);
}
int main()
{
    int num1, num2;
    cout << "Enter first number:";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    //! Naive Approach
    cout << "Naive Approach " << lcm_(num1, num2) << endl;

    //! Efficient Approach
    // num1 * num2 = lcm * gcd
    cout << "Efficient Approaach " << lcm(num1, num2) << endl;
}
