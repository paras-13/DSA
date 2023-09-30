// Algorithm for insertion sort
/*
    Time Complexity analysis:- 
     --> Worst case Analysis:- O[n^2]
     --> Average time Complexity :- O[n^2];
     --> Best Time Complexity :- O[n];

     -> Auxiliary - Space :- O[1];
*/
 // Algo -->
#include <iostream>
using namespace std;
void insertion_sort(int* arr, int size);
void print(int arr[], int size);

int main()
{
    int n;
    cout << "Enter number of elements: "; cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << "Original: "; print(arr, n);
    insertion_sort(arr, n);
    cout << endl << "After sorting: "; print(arr, n);
    return 0;
}

void insertion_sort(int* arr, int size)         // Sorting Algo
{
    int key, j;
    for(int i=0; i<size; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int size)
{
    for(int i=0; i<size; i++) cout << arr[i] << " ";
}