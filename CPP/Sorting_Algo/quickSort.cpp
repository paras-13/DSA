/*
Quick Sort Algorithm

Description:
- Quick Sort is a divide-and-conquer algorithm that selects a 'pivot' element and partitions the array around the pivot, placing smaller elements to the left and larger elements to the right.

Explanation:
1. Choose a pivot element from the array.
2. Partition the array into two subarrays: elements less than the pivot and elements greater than the pivot.
3. Recursively apply the above steps to the subarrays.

Intuition:
- The intuition behind Quick Sort is to reduce the problem size by partitioning the array around a pivot, ensuring that the pivot is in its correct position in the sorted array.

Complexity:
- Time Complexity: Average case O(n log n), Worst case O(n^2) (when the smallest or largest element is always chosen as the pivot).
- Space Complexity: O(log n) due to the recursive stack space.

Advantages:
- In-place sort: Requires only a small, constant amount of additional storage space.
- Efficient for large datasets: Generally faster than other O(n log n) algorithms like Merge Sort for large datasets.

Disadvantages:
- Unstable sort: Does not maintain the relative order of equal elements.
- Worst-case performance: Can degrade to O(n^2) if the pivot selection is poor.
*/

// Quick Sort
#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int beg, int end)
{
    int pivot = arr[beg];
    int i = beg;
    int j = end;
    while (i < j)
    {
        while (pivot >= arr[i] && i < end)
            i++;
        while (pivot < arr[j] && j > beg)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[beg], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int beg, int end)
{
    if (beg < end)
    {
        int partitionIndex = partition(arr, beg, end);

        // Recursively sort elements before and after partition
        quickSort(arr, beg, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
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
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Original array: ";
    printArr(arr);
    quickSort(arr, 0, n - 1);
    cout << endl
         << "Sorted array: ";
    printArr(arr);
}