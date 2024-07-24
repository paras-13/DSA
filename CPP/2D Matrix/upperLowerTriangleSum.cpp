// Find Sum of Upper and Lower triangle in an NxN matrix;
// Time Complexity: O(N*N)
#include <iostream>
#include <vector>
using namespace std;
vector<int> findSum(vector<vector<int>>& matrix, int n) {
    int i, j;
    int upperSum=0, lowerSum = 0;
    
    // Upper Triangle Sum
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i<=j)
                upperSum += matrix[i][j];
        }
    }

    // Lower Triangle Sum
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i >= j)
                lowerSum += matrix[i][j];
        }
    }
    return {upperSum, lowerSum};
}
int main() {
    int n, m, val;
    cout << "Enter value of n: ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> val;
            matrix[i][j] = val;
        }
    }
    vector<int>result = findSum(matrix, n);
    cout << "Upper Triangle Sum: " << result[0] << endl;
    cout << "Lower Triangle Sum: " << result[1] << endl;
}
