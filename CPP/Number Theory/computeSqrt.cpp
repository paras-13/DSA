// To Compute Sqrt of number in nearest Integer, using LogN Time Complexty
// Approach :- Binary Search
// Time :- O(LogN) , Spaace = O(1);

#include <iostream>
int sqrt(int n) {
	// Using Binary Search approach
	int left = 0;
	int right = n;
	int res=  0;
	while(left <= right) {
		long long mid = (left+right)/2;
		if(mid*mid == n)					// Using long long for mid as mid*mid may cross integer limit i.e; 2^31 - 1;
			return mid;
		else if(mid*mid < n){
			res = mid;
			left = mid+1;
		}
		else
			right = mid-1;
	}
	return res;
}
using namespace std;
int main() {
	int n;
	cout << "Enter number: ";
	cin >> n;
	cout << "Nearest Integer Square Root is: " << sqrt(n);
}