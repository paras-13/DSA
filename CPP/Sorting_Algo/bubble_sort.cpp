// Bubble Sort Sorting Algorithm 
/*
-> Simplest Sorting Algorithm
-> Repeatedly swapping the adjacent elements if they are in wrong order
-> But not useful for large data sets (as its average and worst-case time complexity's are high)

-> Time Complexity :- O[n^2]
-> Auxiliary Space :- O[1]

BEST CASE :- The best case occurs when the array is already sorted, swaps required = 0.
             Best case complexity is O(N).

WORST CASE :- When elements are arranged in decreasing order.
             Worst Case Time Complexity O(N^2)

AVERAGE CASE time Complexity :- Number of comparisons is constant in Bubble Sort. Average case, there are O(N2) comparisons.
*/

// Algo -->
#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size);   // Function definition
void print(int arr[], int size);

int main()                      // Main function
{
    int n;cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];                           
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    cout << endl << "Original Array: ";print(arr, n);
    bubbleSort(arr, n);
    cout << endl << "Updated Array: ";print(arr, n);
    return 0;
}

void bubbleSort(int* arr, int size)     // Bubble sort algo
{
    int flag;
    for(int i=0; i<size; i++)
    {
        flag = 0;
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if(flag!=1) break;
    }
}

void print(int arr[], int size)             // print function
{
    for(int i=0; i<size; i++)
    cout << arr[i] << " ";
}