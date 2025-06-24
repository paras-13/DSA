#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n & (n - 1) == 0)
        cout << n;
    else if (n & 1)
    {
        if ((n & (n + 1)) == (n - 1))
            cout << 1;
        else
            cout << 0;
    }
    else
    {
        if (n % 4 == 0)
            cout << n << endl;
        else
            cout << n + 1 << endl;
    }
    // int Xor = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     Xor ^= i;
    //     if ((i & (i - 1)) == 0)
    //         cout << "Mai hu 2^" << i << "=> ";
    //     cout << i << " => " << Xor << endl;
    // }
    return 0;
}