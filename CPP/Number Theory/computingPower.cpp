// Computing Power pow(x, n);
// Time Complexity:
//? Naive Approach: O(n);
//? Efficient Approach: O(logN);

#include <iostream>
using namespace std;
int computePower(int n1, int n2) {
    int res = 1;
    for(int i=0; i<n2; i++) 
        res *= n1;
    return res;
}

// Recursive Solution
int power(int n1, int n2) {
    if(n2 == 0)
        return 1;
    int temp = power(n1, n2/2);
    temp = temp * temp;
    if(n2%2 == 0)
        return temp;
    else
        return temp*n1;
}
int main() {
    int num1, num2;
    cout << "Enter number: ";
    cin >> num1;
    cout << "Enter power: ";
    cin >> num2;

    //! Naive Approach
    cout << "Naive Approach: " << computePower(num1, num2) << endl;

    //! Efficient Approach
    cout << "Efficient Approach: " << power(num1, num2) << endl;
}