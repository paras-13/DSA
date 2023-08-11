// Search an element using binary search
#include <iostream>
using namespace std;
void BinarySearch(int* arr, int n, int ele)
{
    int beg=0, end=n-1;
    int mid = 0;
    int flag = 0;
    while(beg<=end)
    {
        mid = (beg + end)/2;
        if(arr[mid] == ele)
        {
            flag = 1;
            cout << "Element found at " << mid+1 << " position";
            break;
        }
        else if(arr[mid] < ele)
        beg = mid+1;
        
        else if(arr[mid] > ele)
        end = mid-1;
    }
    if(flag == 0)
    cout << "Element not found";
}
int main()
{
    int n, ele;
    cout << "Enter number of elements in array :- ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements :- ";
    for(int i=0; i<n; i++)
    {
    cout << "> ";
    cin >> arr[i];
    }
    cout << "Enter element which you want to find :- ";
    cin >> ele;
    BinarySearch(arr, n, ele);
    return 0;
}
