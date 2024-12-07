// Alocate minimim number of pages
// maximum number of pages assigned to a student is minium
// Using Binary search
// Time Complexity: O(n*Log[N]);
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// checking the condition that whether mid calculated passws over assumption or not
bool isPossible(vector<int> &arr, int n, int m, int mid) {
  int ct = 1;
  int sum = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] + sum <= mid){
      sum += arr[i];
    }
    else {
      sum = arr[i];
      ct++;
    }
    if(ct > m)
      return false;
  }
  return true;
}
int minimumNumberOfPages(vector<int>&arr, int n, int m) {
  int arraySum = 0;
  int mini = INT_MAX;
  for(int i=0; i<n; i++) {
    arraySum += arr[i];
    mini = min(mini, arr[i]);
  }
  int end = arraySum;
  int beg = mini;
  int res;
  while(beg <= end) {
    int mid = beg + (end-beg)/2;
    if(isPossible(arr, n, m, mid)) {
      res = mid;
      end = mid-1;
    }
    else
      beg = mid+1;
  } 
  return res;
}
int main() {
  int n, m;
  cout << "Enter size of array: ";
  cin >> n;
  vector<int>v(n);
  cout << "Enter array elements in sorted order: ";
  for(int i=0; i<n; i++)
    cin >> v[i];
  cout << "Enter number of students to allocate: ";
  cin >> m;
  cout << minimumNumberOfPages(v, n, m);
}
