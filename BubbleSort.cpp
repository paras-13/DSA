// Bubble sort algorithm
// Optimised
#include<iostream>
using namespace std;
void BubbleSort(int* arr, int n)  // Sorting array using bubble sort
{
    int flag, temp;
    for(int i=0; i<n-1; i++)
    {
        flag = 0;
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                flag = 1;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(flag == 0)
        break;
    }
}
void printarray(int* arr, int n)     // Printing array
{
    for(int i=0; i<n; i++)
    cout << arr[i] << " ";
}
int main()
{
    int n;
    cout << "Enter number of elements to add";
    cin >> n;
    int arr[n];      // Taking array input
    cout << "Enter array elements :- ";
    for(int i=0; i<n; i++){
    cout << "> ";
    cin >> arr[i]; 
    }
    BubbleSort(arr, n);
    printarray(arr, n);
    
}
