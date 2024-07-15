// Transpose of a Matrix
// Vector is a dynamic Array;
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> transpose(vector<vector<int>> &matrix, vector<vector<int>>& newMatrix) {
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            newMatrix[j][i] = matrix[i][j];
        }
    }
    return newMatrix;
}
void print(vector<vector<int>> &matrix) {
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
int main() {
    int n, m;
    cout << "Enter matrix data: ";
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;
    int val;
    vector<vector<int>> matrix(n, vector<int>(m));
    vector<vector<int>> newMatrix(m, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << "Enter [" <<i<<"]"<<"["<<j<<"]: ";
            cin >> val;
            matrix[i][j] = val;
        }
    }
    newMatrix = transpose(matrix, newMatrix);
    print(newMatrix);
}