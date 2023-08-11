// To merge two sorted arrays and result a final sorted array.
#include <iostream>
using namespace std;
void merge(int* arr1, int n1, int* arr2, int n2, int* arr3)
{
    int i=0, j=0, k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++; k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++; k++;
        }
    }
    while(i<n1)
    {
        arr3[k] = arr1[i];
        i++; k++;
    }
    while(j<n2)
    {
        arr3[k] = arr2[j];
        j++; k++;
    }
}
int main()
{
    int n1, n2;
    cout << "Enter number of elements in first array :- ";
    cin >> n1;
    int arr1[n1];
    cout << "Enter array elements :- ";
    for(int i=0; i<n1; i++)
    {
        cout << "> ";
    cin >> arr1[i];
        
    }
    
    cout << "Enter number of elements in second array :- ";
    cin >> n2;
    int arr2[n2];
    cout << "Enter second array elements :-";
    for(int i=0; i<n2; i++){
        cout << "> ";
    cin >> arr2[i];
    }
    
    int arr3[n1+n2];
    merge(arr1, n1, arr2, n2, arr3);
    
    for(int i=0; i<n1+n2; i++)
    cout << arr3[i] << " ";
    return 0;
}
