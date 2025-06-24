#include <iostream>
using namespace std;

// Find XOR of two numbers without using XOR operator
int main()
{
    int a, b;
    cin >> a >> b;
    int res = 0;
    int place = 1;

    while (a || b)
    {
        int n1 = a & 1;
        int n2 = b & 1;

        if (n1 != n2)
        {
            res += place;
        }

        place <<= 1; // Move to the next bit
        a >>= 1;
        b >>= 1;
    }

    cout << res << endl;
    return 0;
}
