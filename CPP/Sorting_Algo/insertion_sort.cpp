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
#include <vector>
using namespace std;
void insertionSort(vector<int> &arr)
{
    int j;
    for (int i = 1; i < arr.size(); i++)
    {
        j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}
void printArr(vector<int> &arr)
{
    for (int it : arr)
        cout << it << " ";
}
int main()
{
    int n;
    cout << "Enter number of elements to enter: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Original arry: ";
    printArr(arr);
    insertionSort(arr);
    cout << endl
         << "Sorted array: ";
    printArr(arr);
}