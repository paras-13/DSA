// Matrix Multiplication
#include <iostream>
#include <vector>
using namespace std;
class Matrix {
    private:
    vector<vector<int>>matrix;
    int n, m;
    public:
    Matrix(int n, int m) {
        this->n = n;
        this->m = m;
        matrix.resize(n, vector<int>(m));
    }
    void addElement(){
        int val;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << "["<<i<<"][" << j << "]: ";
                cin >> val;
                matrix[i][j] = val;
            }
        }
    }
    vector<vector<int>> getMatrix() {
        return matrix;
    }
    void print() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

void matrixMultiplication(vector<vector<int>>M1, vector<vector<int>>M2, vector<vector<int>>&matrix) {
    int r1 = M1.size();
    int c1 = M1[0].size();
    int c2 = M2[0].size();
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            matrix[i][j] = 0;
            for(int k=0; k<c1; k++) {
                matrix[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}
void printMatrix(vector<vector<int>>&matrix) {
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n1, n2, m1, m2;
    cout << "Matrix Multiplication: " << endl;
    cout << "Matrix 1: \n";
    cout << "Enter number of rows: ";
    cin >> n1;
    cout << "Enter number of columns: ";
    cin >> n2;
    Matrix M1(n1, n2);
    cout << "Enter elements in matrix 1: " << endl;
    M1.addElement();
    cout << endl << "Matrix 2: \n";
    cout << "Enter number of rows: ";
    cin >> m1;
    cout << "Enter number of columns: ";
    cin >> m2;
    Matrix M2(m1, m2);
    cout << "Enter elements in matrix 2: " << endl;
    vector<vector<int>>matrix(n1, vector<int>(m2));
    M2.addElement();
    if(n2 == m1) {
        cout << endl << "Matrix 1:" << endl;
        M1.print();
        cout << endl << "Matrix 2" << endl;
        M2.print();
        matrixMultiplication(M1.getMatrix(), M2.getMatrix(), matrix);
        cout << endl << "Final matrix after multiplication: " << endl;
        printMatrix(matrix);
    }
    else 
        cout << "Matrix Multiplication is not possible for these matrices:";
}