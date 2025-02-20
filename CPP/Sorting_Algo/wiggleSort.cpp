/*
Wiggle Sort Algorithm

Description:
Wiggle Sort is a sorting algorithm that rearranges the elements of an array such that they form a sequence where every other element is greater than its neighbors. Specifically, for an array `nums`, after wiggle sorting, the following conditions should hold:
- nums[0] <= nums[1] >= nums[2] <= nums[3] >= nums[4] ...

Explanation:
1. Iterate through the array and for each element at an even index, ensure that it is less than or equal to the next element.
2. For each element at an odd index, ensure that it is greater than or equal to the next element.
3. Swap elements if the conditions are not met.

Intuition:
The intuition behind wiggle sort is to create a sequence where the elements alternate between being greater and smaller than their neighbors, creating a "wiggle" pattern.

Complexity:
- Time Complexity: O(n), where n is the number of elements in the array, because we only need to iterate through the array once.
- Space Complexity: O(1), as we are sorting the array in place without using any additional space.
*/

// Wiggle sort
#include <iostream>
#include <vector>
using namespace std;

void wiggleSort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        if (i & 1 && nums[i] < nums[i - 1])
            swap(nums[i], nums[i - 1]);
        else if (i % 2 == 0 && nums[i] > nums[i - 1])
            swap(nums[i], nums[i - 1]);
    }
}
void printArr(vector<int> &nums)
{
    for (int it : nums)
        cout << it << " ";
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << "Original Array: ";
    printArr(nums);
    wiggleSort(nums);
    cout << "\nAfter wiggle sort: ";
    printArr(nums);
}