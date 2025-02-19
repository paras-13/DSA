// Sort an array of 0s, 1s and 2s - Dutch National Flag Algorithm
// The Dutch National Flag problem is a popular algorithmic problem proposed by Edsger Dijkstra.
// The problem is to sort an array consisting of three distinct elements (or "colors") in a single pass through the array.
// The three elements could be anything, but for simplicity, we'll use 0, 1, and 2.

// The Dutch National Flag algorithm is a simple algorithm that uses three pointers to partition the array into three parts:
// 1. The low pointer points to the beginning of the array.
// 2. The mid pointer points to the current element being processed.
// 3. The high pointer points to the end of the array.

// The algorithm works as follows:
// 1. If the current element is 0, swap it with the element at the low pointer and increment both the low and mid pointers.
// 2. If the current element is 1, leave it in place and increment the mid pointer.
// 3. If the current element is 2, swap it with the element at the high pointer and decrement the high pointer.
// 4. Continue this process until the mid pointer crosses the high pointer.

// The time complexity of the Dutch National Flag algorithm is O(n), where n is the number of elements in the array.
// The space complexity of the algorithm is O(1), as it uses only a constant amount of extra space.

// DNF Algorithm
// Code -->
#include <iostream>
#include <vector>
using namespace std;

void DNF(vector<int> &arr)
{
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    int mid = 0;
    while (mid <= right)
    {
        if (arr[mid] == 0)
        {
            swap(arr[left], arr[mid]);
            mid++;
            left++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[right]);
            right--;
        }
        else
            mid++;
    }
}
void print(vector<int> &arr)
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
    print(arr);
    DNF(arr);
    cout << "\nSorted array: ";
    print(arr);
    return 0;
}