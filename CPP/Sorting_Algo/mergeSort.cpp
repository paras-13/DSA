/*
Merge Sort Algorithm

Description:
Merge Sort is a divide-and-conquer algorithm that divides the input array into two halves, recursively sorts them, and then merges the sorted halves to produce the sorted array.

Explanation:
1. Divide: The array is recursively divided into two halves until each subarray contains a single element.
2. Conquer: Each subarray is sorted individually.
3. Combine: The sorted subarrays are merged to produce the final sorted array.

Intuition:
The intuition behind merge sort is to break down the problem into smaller subproblems (sorting smaller arrays) and then combining the solutions to solve the original problem (sorting the entire array).

Complexity:
- Time Complexity: O(n log n) in all cases (best, average, and worst) because the array is always divided into two halves and merging takes linear time.
- Space Complexity: O(n) due to the temporary array used for merging.

Advantages:
- Stable sort: Maintains the relative order of equal elements.
- Predictable time complexity: Always O(n log n), regardless of the input distribution.
- Suitable for large datasets: Efficient for sorting large datasets that do not fit into memory.

Disadvantages:
- Space complexity: Requires additional space proportional to the size of the input array.
- Not in-place: Requires extra memory for the temporary array used during merging.
*/

// Merge Sort

// Code
#include <iostream>
#include <vector>
using namespace std;
void mergeArray(vector<int> &arr, int beg, int mid, int end)
{
    vector<int> temp;
    int left = beg;
    int right = mid + 1;
    while (left <= mid && right <= end)
    {
        if (arr[left] < arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= end)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = beg; i <= end; i++)
        arr[i] = temp[i - beg]; // i- beg as temp array always starts from 0th index
}
void divideArray(vector<int> &arr, int beg, int end)
{
    if (beg < end)
    {
        int mid = beg + (end - beg) / 2;
        divideArray(arr, beg, mid);
        divideArray(arr, mid + 1, end);
        mergeArray(arr, beg, mid, end);
    }
}
void mergeSort(vector<int> &arr)
{
    divideArray(arr, 0, arr.size() - 1);
    return;
}
void printArr(vector<int> &arr)
{
    for (int it : arr)
        cout << it << " ";
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Unsorted array: ";
    printArr(arr);
    mergeSort(arr);
    cout << endl
         << "Sorted array: ";
    printArr(arr);
}