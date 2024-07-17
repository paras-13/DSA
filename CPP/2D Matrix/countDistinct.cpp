// Count and Display distinct element common to all rows in a 2D matrix;
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Using Map
// Time Complexity: O(n^2)
int countDistinct(vector<vector<int>>& matrix) {
    unordered_map<int, int>mp;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; i++)
        mp[(matrix[0][i])] = 1;
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mp[(matrix[i][j])]!=0 && mp[(matrix[i][j])] == i){
                mp[(matrix[i][j])] = i+1;
                if(i == n-1)
                    cout << matrix[i][j] << " ";
            }
        }
    }
    int count = 0;
    for(auto x : mp){
        if(x.second == n) count++;
    }
    cout << endl << "Count of distinct element: ";
    return count;
}
int main() {
    int n, m, val;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;
    vector<vector<int>>matrix(n, vector<int>(m));
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            cin >> val;
            matrix[i][j] = val;
        }
    }
    cout << "Distinct elements: " << countDistinct(matrix);
}