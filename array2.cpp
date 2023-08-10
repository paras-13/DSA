#include<iostream>
using namespace std;

void Insert(int* arr, int &n, int ele, int pos)
{
    for(int j=n-1; j>=pos-1; j--)
    arr[j+1] = arr[j];
    arr[pos-1] = ele;
    n++;
}
void print(int* arr, int n)
{
    for(int i=0; i<n; i++)
    cout << arr[i] << " ";
    cout << endl  << "Array size :- " << n;
}
int main()
{
    int n;
    cout << "Enter the number of elements you want to enter :- ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements :- " << endl;
    for(int i=0; i<n; i++)
    {
    cout << "> ";
    cin >> arr[i];
    }
    int ele, pos;
    cout << "Enter the element which you want to insert :- ";
    cin >> ele;
    cout << "Enter the position where you want to insert :- ";
    cin >> pos;
    Insert(arr, n, ele, pos);
    print(arr, n);
}
