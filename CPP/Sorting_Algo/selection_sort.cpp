// Selection Sort algorithm 
/*
It is an efficient sorting algorithm which works by repeatedly selecting the smallest 
(or largest) element from the unsorted portion of the list.

Complexity Analysis:- 
 -> Time Complexity :- O[n^2]
 -> Auxiliary Space :- O[1]

 -> Best Case Time Complexity :- O[n^2
 -> Average Case Time Complexity :- O[n^2]
 -> Worst case Time Complexity :- O[n^2]
*/

// This sorting method requires the minimum number of swaps
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
    int ind_min;
    for(int i=0; i<size; i++)
    {
        ind_min = i;
        for(int j=i+1; j<size; j++)
        {
            if(arr[ind_min] > arr[j])
            ind_min = j;
        }
        if(ind_min != i) swap(arr[ind_min], arr[i]);
    }
}
void print(int arr[], int size)
{
    for(int i=0; i<size; i++) cout << arr[i] << " ";
}
