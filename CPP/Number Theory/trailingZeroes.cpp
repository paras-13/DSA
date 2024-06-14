// Count number of Trailing zeroes in Factorial....
// Time Complexity :
//? Naive Approach : O(N);
//? Efficient Approach : O(logN);

#include <iostream>
using namespace std;
int naiveApproach(int n) {
    // First find factorial
    int fact = 1;
    for(int i=2; i<=n; i++) 
        fact *= i;
    
    // Now finding trailing zeroes
    int count = 0;
    while(fact%10 == 0) {
        count++;
        fact/=10;
    }
    return count;
}
int main() {
    int n;
    cout << "Enter a factorial number: ";
    cin >> n;
    // Naive approach;
    cout << "Trailing zeroes " << naiveApproach(n) << endl;


    // Efficient method
    int count = 0;
    while(n>=5) {
        count += n/5;
        n /= 5;
    }
    cout << count << endl;
}