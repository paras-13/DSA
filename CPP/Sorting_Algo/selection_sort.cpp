// Selection Sort algorithm 
/*

*/

// Algo -->
#include <iostream>
using namespace std;

void selectionSort(int *arr, int size);
void print(int arr[], int size);

int main()
{
    int n;
    cout << "Enter number of elements: "; cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << "Original: ";print(arr, n);
    selectionSort(arr, n);
    cout << endl << "After sorting: "; print(arr, n);
}

void selectionSort(int* arr, int size)
{
    
}
void print(int arr[], int size)
{
    
}
