// Print all primes smaller than or equal to n using sieve algorithm

// Time Complexity:
//? Naive Approach: O(N*sqrt(n))
//? Sieve Alogorithm: O(N* log(logN));

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if(n == 1) return false;
    if(n==2 || n==3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i=5; i*i <= n; i+= 6) {
        if(n%i == 0 || n%(i+2) == 0) return false; 
    }
    return true;
}

void primeUptoN(int n) {
    if(n <= 1) return;
    for(int i=2; i<=n; i++) {
        if(isPrime(i)) cout << i << " ";
    }
    return;
}

void sieve(int n, vector<bool>prime) {
    
    if(n <= 1) return;
    for(int i=2; i*i<=n; i++) {
        if(prime[i]) {
            for(int j = 2*i; j <= n; j+= i)
                prime[j] = false;
        }
    }
    for(int i=2; i<=n; i++) {
        if(prime[i]) cout << i << " ";
    }

    
    return;
}
int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;
    vector<bool> prime(num+1, true);

    // //! Naive Approach:
    cout << "Naive Approach: ";
    primeUptoN(num);
    cout << endl;

    //! Sieve Algorithm:
    cout << "Sieve Algorithm ";
    sieve(num, prime);
    cout << endl;

    //! More Optimised Approach for sieve
    for(int i=2; i <=num; i++) {
        if(prime[i]) {
            cout << i << " ";
            for(int j = i*i; j<=num; j+= i)
                prime[j] = false;
        }
    }
}