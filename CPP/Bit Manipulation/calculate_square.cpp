// Calculate square of a umber without using *, / and pow() operator

/*
    if n is even it can be represeted as
    n  = 2*x
        => n^2 = 4*x^2
        => n^2 = 4*(x/2)^2

        ==> why x/2 as
                => n = 2*x
                => n/2 = x

    and if n is odd it can be represented as
    n = 2*x + 1;
        => n^2 = 4*x^2 + 4*x + 1;
        => n^2 = 4*floor(x/2)^2 + 4*floor(x/2) + 1;

        => now why floor
            => n = 2*x + 1
            => (n-1)/2 = x;
            => x is floor(n/2);

    to perform division operation we can use right shift and for multiplication we can use left shift


    So we can perform operations
    like
    ? for even number
        => square(x) << 2 => (x/2)^2 * 4;

    ? for odd number
        => square(x) << 2 + x << 2 + 1  => (x/2)^2*4 + (x/2)*4
*/

#include <iostream>
using namespace std;
int square(int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        n = -n;
    int x = n >> 1; // right shift for floor(n/2);
    if (n & 1)
        return ((square(x) << 2) + (x << 2) + 1);
    return (square(x) << 2);
}
int main()
{
    int n;
    cin >> n;
    cout << square(n) << endl;
}