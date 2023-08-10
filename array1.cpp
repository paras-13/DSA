#include<iostream>
using namespace std;

void Delete(int* arr, int &n, int ele)
{
    int ind;
    for(int i=0; i<n; i++){
        if (arr[i] == ele) ind = i;
    }
    for(int j=ind; j<n-1; j++)
    arr[j] = arr[j+1];
    n--;
}
void print(int* arr, int n)
{
    for(int i=0; i<n; i++)
    cout << arr[i] << " ";
    cout << ele  << "Array size :- " << n;
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
    int ele;
    cout << "Enter the element which you want to delete :- ";
    cin >> ele;
    Delete(arr, n, ele);
    print(arr, n);
}
