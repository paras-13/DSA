#include <iostream>
using namespace std;
int check_prime(int num)
{
	if(num<2) return 0;
	else if(num == 2) return 1;
	else
	{
		for(int i=2; i<num/2; i++)
		{
			if(num%i == 0)
			return 0;
		}
		return 1;

	}
}
int main() {
	int num;
	cin >> num;
	while(num--)
	{
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
		cin >> arr[i];
		int count = 0;
		int prime;
		for(int i=0; i<n; i++)
		{
			for(int j=n-1; j>i+1; j--)
			{
				for(int k=i+1; k<j; k++)
				{
					prime = arr[i]*arr[j]*arr[k];
					if(check_prime(prime)) count++;
					j--;
				}
			}
		}
		cout << count << endl;
	}
}
