// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int j=0;
    for(int i=0; i<size; i++)
    {
        if(arr[i] <0){
            if(i!=j){
                swap(arr[i], arr[j]); j++;
            }
        }
    }
    for(int k=0; k<size; k++)
    cout << arr[k] <<" ";
    return 0;
}
