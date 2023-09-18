// Array linear Search using element
#include<iostream>
using namespace std;
int linear_search(int* arr, int ele, int n)
{
    int i;
    for(i=0; i<n; i++)
    if(arr[i] == ele) break;
    return i+1;
}
int main()
{
    int n, ele;
    cout << "Enter number of elements to enter: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    cout << "Enter the element which you want to search: ";
    cin >> ele;
    cout << "Element " << ele <<" found at " <<linear_search(arr, ele, n)<<" position";

}