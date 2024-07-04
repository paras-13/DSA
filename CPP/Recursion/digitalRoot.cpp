// Digital Root of a number
#include <iostream>
using namespace std;
int digitalRoot(int n) {
    int sum = 0;
    while(n!=0) {
        sum += n%10;
        n /= 10;
    }
    if(sum >= 10)
        sum = digitalRoot(sum);
    return sum;
}
int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << digitalRoot(n) << endl;
}