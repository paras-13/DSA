// Josephus Problem  (Recursive Problem)
#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n == 0)
        return 0;
    int x = josephus(n - 1, k);
    int y = (x + k-1) % n+1;
    return y;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k);
}