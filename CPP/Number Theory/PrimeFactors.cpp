// Prime Factors of a given number

// Time Complexity
//? Naive Approach: O(NlogN)
//? Efficient Approach: O(sqrt(n))

#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n) {
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i=5; i<=sqrt(n); i+=6) {
        if(n%i == 0 || n%(i+2) == 0) return false;
    }
    return true;
}

void primeFactorsNaive(int n) {
    int temp = n;
    for(int i=2; i<=temp; i++) {
        if(isPrime(i)) {
            while(n%i == 0) {
                cout << i << " ";
                n/=i;
            }
        }
    }
}

void primeFactors(int n) {
    if(n <=1 ) return;
    for(int i=2; i*i <= n; i++) {
        while(n%i == 0){
            cout << i << " ";
            n /= i;
        }
    }
    if(n > 1 )
        cout << n;
}

void prime_factors(int n) {
    if(n <= 1) return;
    while(n%2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }
    while(n%3 == 0) {
        cout << 3 << " ";
        n /= 3;
    }
    for(int i=5; i*i <= n; i+=6) {
        while(n%i == 0) {
            cout << i << " ";
            n /= i;
        }
        while(n%(i+2) == 0) {
            cout << i+2 << " ";
            n /= (i+2);
        }
    }
    if(n > 3) cout << n << endl;
}

int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;

    //! Naive Approach
    cout << "Naive Approach: ";
    primeFactorsNaive(num);

    //! Efficient Approach
    cout << "\nEfficient Approach: ";
    primeFactors(num);

    //! More Efficient (3 times faster than efficient approach)
    cout << "\nMost Efficient: ";
    prime_factors(num);

}