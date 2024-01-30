// Print numbers using Recursion
#include <iostream>
using namespace std;
void printAsc(int n)
{
    if(n == 0)
        return;
    printAsc(n-1);
    cout << n << " ";
    return;             // return is optional
}
void printDsc(int n)
{
    if(n == 0) 
        return;
    cout << n << " ";
    printDsc(n-1);
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "In Ascending Order: ";
    printAsc(n);
    cout << endl << "In Descending Order: ";
    printDsc(n);
}